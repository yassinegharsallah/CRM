#include "offreui.h"
#include "offre.h"
#include <QString>
#include <QMessageBox>

 void offreui::MainWindow::on_pushButton_7_clicked()
 {
     bool ok ;
     MainWindow m;
     QString x=ui->ref->text();    

     QString a=ui->nomoffre->text();
     QString b=ui->datajout->text();
     QString c=ui->datexpira->text();
     QString d=ui->comboBoxcible->currentText();
     QString e=ui->desc->text();
      int y = x.toInt(&ok,10);
     offre p(y,a,b,c,d,e) ;
     if(p.ajouter())
     {
         ui->tableView_2->setModel(p.afficher());
         qDebug()<<"offre ajouter";
         qDebug()<<x;
         ntf->show();
         ntf->showMessage("une offre a eté ajouté",d,QSystemTrayIcon::Information,30000);
        // m.SetNotif(true);
         QMessageBox::information(this,"Ajout effectué","Offre ajouté");
     }
     else
     {
         qDebug()<<"offre non ajouter";
     }
 }
void offreui::MainWindow::on_pushButton_3_clicked()
{



    bool ok ;
    QString x=ui->refmodifier->text();
    QString a=ui->lineEdit_3->text();
    QString b=ui->lineEdit_4->text();
    QString c=ui->lineEdit_5->text();
    QString d=ui->lineEdit_6->text();
    QString e=ui->lineEdit_7->text();
    int y = x.toInt(&ok,10);
    offre p (y,a,b,c,d,e);
   if(p.modifier())
   {
       qDebug()<<"offre modifier";
       ui->tableView->setModel(p.afficher());
       QMessageBox::information(this,"info","offre modifé avec succées");


   }
   else
   {
       qDebug()<<"offre non modifie";
   }
}
void offreui::MainWindow::on_pushButton_5_clicked()
{

    bool ok ;
    QString x=ui->refmodifier->text();
    QString a=ui->lineEdit_3->text();
    QString b=ui->lineEdit_4->text();
    QString c=ui->lineEdit_5->text();
    QString d=ui->lineEdit_6->text();
    QString e=ui->lineEdit_7->text();
    int y = x.toInt(&ok,10);
    offre p (y,a,b,c,d,e);
        if (p.supprimer())
        {
            ui->tableView->setModel(p.afficher());
            qDebug() << "offre supprimer";
            QMessageBox::information(this,"info","offre suprrimé avec succées");
        }
        else
            qDebug() << "offre non supprimer";
}
void offreui::MainWindow::on_pushButton_6_clicked()
{

    offre p;
    ui->tableView->setModel(p.afficher());
}
