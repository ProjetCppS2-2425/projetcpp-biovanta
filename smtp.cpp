#include "smtp.h"

Smtp::Smtp(const QString &user, const QString &pass, const QString &host, qint16 port, int timeout)
{
    socket = new QSslSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(errorReceived(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    this->user = user;
    this->pass = pass;
    this->host = host;
    this->port = port;
    this->timeout = timeout;
}

Smtp::~Smtp()
{
    delete t;
    delete socket;
}

void Smtp::sendMail(const QString &from, const QString &to, const QString &subject, const QString &body, QStringList files)
{
    message = "To: " + to + "\n";
    message.append("From: " + from + "\n");
    message.append("Subject: " + subject + "\n");
    message.append("MIME-Version: 1.0\n");
    message.append("Content-Type: multipart/mixed; boundary=frontier\n\n");

    message.append("--frontier\n");
    message.append("Content-Type: text/plain\n\n");
    message.append(body + "\n\n");

    foreach (QString filePath, files)
    {
        QFile file(filePath);
        if (file.exists() && file.open(QIODevice::ReadOnly)) {
            QByteArray bytes = file.readAll();
            message.append("--frontier\n");
            message.append("Content-Type: application/octet-stream\n");
            message.append("Content-Disposition: attachment; filename=" + QFileInfo(file.fileName()).fileName() + "\n");
            message.append("Content-Transfer-Encoding: base64\n\n");
            message.append(bytes.toBase64());
            message.append("\n");
        }
    }

    message.append("--frontier--\n");
    message.replace(QString::fromLatin1("\n"), QString::fromLatin1("\r\n"));
    message.replace(QString::fromLatin1("\r\n.\r\n"), QString::fromLatin1("\r\n..\r\n"));

    this->from = from;
    rcpt = to;
    state = Init;

    socket->connectToHostEncrypted(host, port);
    if (!socket->waitForConnected(timeout)) {
        qDebug() << "Erreur de connexion:" << socket->errorString();
    }

    t = new QTextStream(socket);
}

void Smtp::stateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "État de socket:" << socketState;
}

void Smtp::errorReceived(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Erreur de socket:" << socketError;
}

void Smtp::disconnected()
{
    qDebug() << "Déconnecté. Erreur:" << socket->errorString();
}

void Smtp::connected()
{
    qDebug() << "Connecté au serveur SMTP.";
}

void Smtp::readyRead()
{
    QString responseLine;
    do {
        responseLine = socket->readLine();
        response += responseLine;
    } while (socket->canReadLine() && responseLine[3] != ' ');

    responseLine.truncate(3);
    qDebug() << "Réponse du serveur:" << response;

    if (state == Init && responseLine == "220") {
        *t << "EHLO localhost\r\n";
        t->flush();
        state = HandShake;
    }
    else if (state == HandShake && responseLine == "250") {
        socket->startClientEncryption();
        if (!socket->waitForEncrypted(timeout)) {
            qDebug() << socket->errorString();
            state = Close;
        }
        *t << "EHLO localhost\r\n";
        t->flush();
        state = Auth;
    }
    else if (state == Auth && responseLine == "250") {
        *t << "AUTH LOGIN\r\n";
        t->flush();
        state = User;
    }
    else if (state == User && responseLine == "334") {
        qDebug() << "Envoi du nom d'utilisateur...";
        *t << user.toUtf8().toBase64() << "\r\n";
        t->flush();
        state = Pass;
    }
    else if (state == Pass && responseLine == "334") {
        qDebug() << "Envoi du mot de passe...";
        *t << pass.toUtf8().toBase64() << "\r\n";
        t->flush();
        state = Mail;
    }
    else if (state == Mail && responseLine == "235") {
        *t << "MAIL FROM:<" + from + ">\r\n";
        t->flush();
        state = Rcpt;
    }
    else if (state == Rcpt && responseLine == "250") {
        *t << "RCPT TO:<" + rcpt + ">\r\n";
        t->flush();
        state = Data;
    }
    else if (state == Data && responseLine == "250") {
        *t << "DATA\r\n";
        t->flush();
        state = Body;
    }
    else if (state == Body && responseLine == "354") {
        *t << message << "\r\n.\r\n";
        t->flush();
        state = Quit;
    }
    else if (state == Quit && responseLine == "250") {
        *t << "QUIT\r\n";
        t->flush();
        emit status("Message envoyé avec succès.");
    }
    else if (state == Close) {
        deleteLater();
    }
    else {
        emit status("Échec de l'envoi du message.");
        state = Close;
    }
}
