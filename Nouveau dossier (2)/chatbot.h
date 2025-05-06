#ifndef CHATBOT_H
#define CHATBOT_H

#include <QObject>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include "geminiapi.h"

class Chatbot : public QObject
{
    Q_OBJECT
public:
    explicit Chatbot(QTextEdit *chatTextEdit,
                     QLineEdit *inputLineEdit,
                     QPushButton *sendButton,
                     QObject *parent = nullptr);

private slots:
    void handleSendMessage();
    void handleGeminiResponse(const QString &response);

private:
    QTextEdit *m_chatTextEdit;
    QLineEdit *m_inputLineEdit;
    QPushButton *m_sendButton;
    GeminiAPI *m_gemini;
};

#endif // CHATBOT_H
