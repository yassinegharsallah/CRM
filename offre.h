#ifndef OFFRE_H
#define OFFRE_H
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include<QTableView>

class offre
{
int ref;
QString  nom;
QString dateajout;
QString datexpiration;
QString client_cible;
QString description;
public:
    offre();
    offre(int,QString,QString,QString,QString,QString);
    bool ajouter();
    bool modifier();
    bool supprimer();
    QSqlQueryModel *afficher();



};

#endif // OFFRE_H
