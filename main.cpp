    #include "mainwindow.h"
    #include <QApplication>

    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
        MainWindow w;
        QSqlDatabase db;
        db=QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("ESPRIT");
        db.setUserName("ESPRIT2A");
        db.setPassword("esprit");

        if(db.open())
        {


            qDebug()<<"connection etablie";

        }
        else
        {
            qDebug()<<"connection faild"<<db.lastError().text();
        }
        w.show();
        //QSqlQuery *q=new QSqlQuery(db);
        //q->exec("INSERT INTO OFFRE(NOM,DATEAJOUT,DATEXPIRATION,CLIENT_CIBLE,ACTIVITÉ,DESCRIP TION) VALUES('aa','aaa','aaa','aaaa','aaaa','aaa')");

        return a.exec();
    }
