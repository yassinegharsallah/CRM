#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSql>
#include<QtSql/QSqlDatabase>
#include <QtSql>
#include <QFileInfo>
#include <QSystemTrayIcon>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool GetNotif(){return notif;}
    void SetNotif(bool value){notif=value;}

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void DislayPlots(QWidget *x);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    virtual void on_pushButton_5_clicked();

   virtual void on_pushButton_3_clicked();

    virtual void on_pushButton_6_clicked();

    virtual void on_pushButton_7_clicked() ;

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void on_actionFermeture_session_triggered();

    void on_actionD_connexion_triggered();

    void on_actionParam_tres_triggered();

    void on_actionSave_as_triggered();

    void on_actioncut_triggered();

    void on_actioncopy_triggered();

    void on_actionpaste_triggered();

    void on_actionredo_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_23_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();


    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_Tri_clicked();

    void on_tableView_4affceter_activated(const QModelIndex &index);

    void on_affecter_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_27_clicked();

    void on_checkBox_clicked();

    void on_home_clicked();

  //  void on_pushButton_28_clicked();

    //void on_pushButton_22_clicked();

    void on_pushButton_25_clicked();

protected:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString file_path;
    bool notif;
    QSystemTrayIcon *ntf;
};

#endif // MAINWINDOW_H
