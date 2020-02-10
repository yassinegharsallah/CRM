#ifndef OFFREUI_H
#define OFFREUI_H
#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSql>
#include<QtSql/QSqlDatabase>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QMessageBox>
class offreui: public MainWindow
{
public:

  void on_pushButton_7_clicked();
void on_pushButton_3_clicked();
void on_pushButton_5_clicked();
void on_pushButton_6_clicked();
};

#endif // OFFREUI_H
