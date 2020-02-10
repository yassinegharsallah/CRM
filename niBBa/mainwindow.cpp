
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <Qdebug>
#include "offre.h"
#include "smtp.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ntf = new QSystemTrayIcon(this);
    ntf->setIcon(QIcon("Desktop\\instagram\\push-notification.png"));



   /* offre r;
    r.afficher_notification(ui->tableView_4);

    if(r.notification())
    {
        QPixmap notifi("C:/Users/mahdi/Desktop/photo qt/rec");

        ui->noti->setPixmap(notifi);
    }*/


}





MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString password;
    QString username;
    password = ui->lineEdit_2->text();
    username = ui->lineEdit->text();
    if(password=="admin"&&username=="esprit")
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
     QMessageBox::warning(this,"warning","username or password uncorrect");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_14_clicked()
{
    QString from = ui->from->text();
    QString to = ui->to->text();
    QString subject = ui->subject->text();
    QString mail=ui->lineEdit->text();
    Smtp *newMail  = new Smtp();
    newMail->setFrom(from);
    newMail->setMessage(mail);
    newMail->setSubject(subject);
    newMail->setRcpt(to);
    newMail->sendMail();
    delete newMail;

}

void MainWindow::on_actionFermeture_session_triggered()
{
    file_path="";
    ui->textEdit_2->setText("");
}

void MainWindow::on_actionD_connexion_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"open the file") ;
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"","file not open");
        return;
    }
  QTextStream in(&file);
  QString text = in.readAll();
  ui->textEdit_2->setText(text);
  file.close();
}

void MainWindow::on_actionParam_tres_triggered()
{
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"","file not open");
        return;
    }
  QTextStream out(&file);
  QString text = ui->textEdit_2->toPlainText();
  out << text;
  file.flush();
  file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"open the file") ;
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"","file not open");
        return;
    }
  QTextStream out(&file);
  QString text = ui->textEdit_2->toPlainText();
  out << text;
  file.flush();
  file.close();
}

void MainWindow::on_actioncut_triggered()
{
    ui->textEdit_2->cut();
}

void MainWindow::on_actioncopy_triggered()
{
    ui->textEdit_2->copy();
}

void MainWindow::on_actionpaste_triggered()
{
    ui->textEdit_2->paste();
}

void MainWindow::on_actionredo_triggered()
{
   ui->textEdit_2->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit_2->undo();
}

void MainWindow::on_actionAbout_triggered()
{
    QString about_text;
    about_text="Auther : Yassin";
    about_text+="Date 2017-11-16";
    about_text+="(c) All rights reserved to myself (R)";

    QMessageBox::about(this,"about notepad",about_text);

}

void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_16_clicked()
{
    MainWindow x;
    ui->stackedWidget->setCurrentIndex(1);
    if(x.GetNotif()==true)
    {
        QPixmap pixel("Desktop\\instagram\\globe.png");
        ui->notifica->setPixmap(pixel);
    }


}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_18_clicked()
{
    QString search_line= ui->search_line->text();
    QSqlQuery *q=new QSqlQuery();
    QSqlQueryModel *m=new QSqlQueryModel();
        if(   q->exec("SELECT * FROM OFFRES WHERE CLIENT_CIBLE= '"+search_line+"'  " ) )
                {
                    m->setQuery(*q);
                    ui->tableView->setModel(m);
                }
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/*void MainWindow::on_pushButton_24_clicked()
{
    QBarSet  *set0=new QBarSet("Garcon");
        QBarSet  *set1=new QBarSet("Fille");

        *set0<<moyM;
        *set1<<0<<moyF;

        QBarSeries *barseries=new QBarSeries();
        barseries->append(set0);
        barseries->append(set1);

        QChart *chart =new QChart();
        chart->addSeries(barseries);
        chart->setTitle("Statistique global des eleves par sexe");

        QStringList categories;
        categories << "Garcon"<<"Fille";

        QBarCategoryAxis *AxisX=new QBarCategoryAxis();
        AxisX->append(categories);
        chart->setAxisX(AxisX,barseries);
        AxisX->setRange(QString("Garcon"),QString("Fille"));

        QValueAxis *AxisY =new QValueAxis();
        chart->setAxisY(AxisY,barseries);
        AxisY->setRange(0,100);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartview=new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chart->setAnimationOptions(QChart::AllAnimations);
        chartview->resize(800,600);
        chartview->show();
}
*/

void MainWindow::on_pushButton_20_clicked()
{
    QString search_line= ui->line_editDateAjoutrv->text();
    QString date =ui->lineEdit_dexpiration->text();
    QSqlQuery *q=new QSqlQuery;
    QSqlQueryModel *m=new QSqlQueryModel();
        if(   q->exec("SELECT * FROM OFFRES WHERE DATEAJOUT = '"+search_line+"' AND DATEXPIRATION = '"+date+"'  " ) )
                {
                    m->setQuery(*q);
                    ui->tableView_3->setModel(m);
                }
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_Tri_clicked()
{
    QString search_line= ui->line_editDateAjoutrv->text();
    QString date =ui->lineEdit_dexpiration->text();
    QSqlQuery *q=new QSqlQuery;
    QSqlQueryModel *m=new QSqlQueryModel();
        if(   q->exec("SELECT * FROM OFFRES ORDER BY REF " ) )
                {
                    m->setQuery(*q);
                    ui->tableView_3->setModel(m);
                }

}

void MainWindow::on_tableView_4affceter_activated(const QModelIndex &index)
{
    QString val =ui->tableView_4affceter->model()->data(index).toString();
    QSqlQuery qry ;
    qry.prepare("select * from PARENT where NOM='"+val+"' or PRENOM='"+val+"' ");
    if (qry.exec())
        {
        while (qry.next())
            {
            ui->nomparent->setText(qry.value(0).toString());
             ui->prenomparent->setText(qry.value(1).toString());
        }
    }

}

void MainWindow::on_affecter_clicked()
{
    QSqlQuery qry;
        QString nom = ui->nomparent->text();
        QString prenom = ui->prenomparent->text();
        QString offre = ui->comboxaffect->currentText();
        qry.prepare("UPDATE PARENT set offre=:offre where nom=:nom");
        qry.bindValue(":nom",nom);
        qry.bindValue(":prenom",prenom);
        qry.bindValue(":offre",offre);
        qry.exec();
        QMessageBox::information(this,"info","offre affecté avec succées");


}

void MainWindow::on_pushButton_26_clicked()
{
    QSqlQueryModel *Model=new QSqlQueryModel();
        QSqlQuery query;

        query.prepare("SELECT * FROM PARENT ");

        query.exec();

        Model->setQuery(query);
        ui->tableView_4affceter->setModel(Model);
        if (query.exec())
                qDebug()<<"Affichage reussi =) ";
            else
                qDebug()<<"Echec =( ";


}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_checkBox_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



/*void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}*/

