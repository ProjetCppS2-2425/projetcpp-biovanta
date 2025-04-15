#include "chatbot.h"
#include <QTime>
#include <QDebug>



void Chatbot::handleSendMessage()
{
    QString userInput = m_inputLineEdit->text().trimmed();

    if (userInput.isEmpty())
        return;

    m_chatTextEdit->append("<b>Vous:</b> " + userInput);
    m_chatTextEdit->append("<i>Gemini réfléchit...</i>");
    m_chatTextEdit->append("");

    m_inputLineEdit->clear();

    // Débogage : Afficher la requête envoyée
    qDebug() << "Sending user input to Gemini:" << userInput;

    m_gemini->askGemini(userInput);
}

void Chatbot::handleGeminiResponse(const QString &response)
{
    // Supprimer le "Gemini réfléchit..." s'il est là
    QString currentText = m_chatTextEdit->toPlainText();
    if (currentText.endsWith("Gemini réfléchit...\n"))
    {
        QTextCursor cursor = m_chatTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.movePosition(QTextCursor::StartOfBlock, QTextCursor::KeepAnchor);
        cursor.removeSelectedText();
        cursor.deletePreviousChar(); //men andou
    }

    m_chatTextEdit->append("<b>Gemini:</b> " + response);
    m_chatTextEdit->append("");
}
