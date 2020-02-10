#include "smtp.h"

Smtp::Smtp(  )
{}
Smtp::~Smtp()
{
}

void Smtp::sendMail ()
{
        // This is a first demo application of the SmtpClient for Qt project

        // First we need to create an SmtpClient object
        // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and the password
        // for smtp authentification.

        smtp.setUser("yassine.bengharsallah@esprit.tn");
        smtp.setPassword("ommihafsia008");

        // Now we create a MimeMessage object. This will be the email.
        MimeMessage message;

        message.setSender(new EmailAddress(this->from, "Admin"));
        message.addRecipient(new EmailAddress(this->rcpt, "User"));
        message.setSubject("Thank you !");

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText(this->message);

        // Now add it to the mail

        message.addPart(&text);
        // Now we can send the mail

        if (!smtp.connectToHost()) {
            qDebug() << "Failed to connect to host!" << endl;
          //  return -1;
        }

        if (!smtp.login()) {
            qDebug() << "Failed to login!" << endl;
            //return -2;
        }

        if (!smtp.sendMail(message)) {
            qDebug() << "Failed to send mail!" << endl;
            //return -3;
        }

        smtp.quit();
    }
