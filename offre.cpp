 #include "offre.h"
offre::offre()
{
this->nom="";
this->dateajout="";
this->datexpiration="";
this->client_cible="";
this->description="";
this->ref=0;
}
offre::offre(int m_ref,QString m_nom,QString m_dateajout,QString m_datexpiration,QString mclient_cible,QString m_description)
{
    this->nom=m_nom;
    this->dateajout=m_dateajout;
    this->datexpiration=m_datexpiration;
    this->client_cible=mclient_cible;
    this->description=m_description;
    this->ref=m_ref;
}

bool offre::ajouter()
{
    QSqlQuery query;
    query.prepare("insert into OFFRES (REF,NOM,DATEAJOUT,DATEXPIRATION,CLIENT_CIBLE,DESCRIPTION) "
                  "VALUES(:ref,:nom,:dateajout,"
                  ":datexpiration,:client_cible"
                  ",:description)");
    query.bindValue(":ref",ref);
    query.bindValue(":nom",nom);
    query.bindValue(":dateajout",dateajout);
    query.bindValue(":datexpiration",datexpiration);
    query.bindValue(":client_cible",client_cible);
    query.bindValue(":description",description);

    qDebug() << "Query exec() error. " << query.lastError();
    return (query.exec());
}

QSqlQueryModel * offre::afficher()
{

    QSqlQueryModel *Model=new QSqlQueryModel();
        QSqlQuery query;

        query.prepare("SELECT * FROM OFFRES ");
        query.exec();

        Model->setQuery(query);

        if (query.exec())
                qDebug()<<"Affichage reussi =) ";
            else
                qDebug()<<"Echec =( ";

        return Model;


}

bool offre::supprimer()
{
    QSqlQuery qry;
    qry.prepare("Delete from OFFRES where Ref=?");

                 qry.addBindValue(ref);
     return (qry.exec());

}


bool offre::modifier()
{
   QSqlQuery qry;

       qry.prepare("UPDATE OFFRES set NOM=:nom,DATEAJOUT=:dateajout,DATEXPIRATION=:datexpiration,CLIENT_CIBLE=:client_cible,DESCRIPTION=:description where Ref=:ref");

       qry.bindValue(":ref",ref);
       qry.bindValue(":nom",nom);
       qry.bindValue(":dateajout",dateajout);
       qry.bindValue(":datexpiration",datexpiration);
       qry.bindValue(":client_cible",client_cible);
       qry.bindValue(":description",description);

        if(qry.exec())
        return true;
        qDebug()  << qry.lastError();
        return false;
    return (qry.exec());
}




/*
bool offre::notification()
{
QSqlQuery query ("SELECT NOTIFICQTION FROM OFFRES");

    while (query.next())
    {
        QString country=query.value(0).toString();
        if (country=='0')
            return true;
    }
    return false;
}



void offre::afficher_notification(QTableView *g)
{
    QSqlQuery *q=new QSqlQuery();
    QSqlQueryModel *m=new QSqlQueryModel();

    if (q->exec("SELECT * FROM OFFRES WHERE NOTIFICQTION = 0"));
    { m->setQuery(*q);
        g->setModel(m);
     }

}



void offre::check()
{
    QSqlQuery q("SELECT NOTIFICQTION FROM OFFRES");
    while (q.next())
    {
    q.prepare("UPDATE OFFRES SET NOTIFICQTION = 1");
    q.exec();

    }
}
*/
