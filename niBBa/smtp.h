#ifndef SMTP_H
#define SMTP_H


#include <QTcpSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "src/SmtpMime"
class Smtp
{


public:
    Smtp( );
    ~Smtp();
    void setMessage(QString m){this->message = m;}
    void setFrom(QString m){this->from = m ;}
    void setRcpt(QString m){this->rcpt = m;}
    void setSubject(QString m){this->subject = m;}
    void sendMail();
private:
    QString message;
    QString from;
    QString rcpt;
    QString subject;

};

#endif // SMTP_H
