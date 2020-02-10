#-------------------------------------------------
#
# Project created by QtCreator 2017-10-31T21:40:57
#
#-------------------------------------------------

QT       += core gui sql
QT += network serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



TARGET = niBBa
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    offre.cpp \
    offreui.cpp \
    smtp.cpp

HEADERS += \
        mainwindow.h \
    offre.h \
    offreui.h \
    smtp.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    src.qrc \
    srcx.qrc

DISTFILES += \
    ../../crm/stats.png \
    ../../crm/custom-icon-design-flatastic-10-open-file.ico \
    ../../crm/custom-icon-design-flatastic-10-open-file.ico \
    ../../instagram/document_add.png \
    ../../instagram/1328102001_Undo.png \
    ../../instagram/Redo.png \
    ../../instagram/Save-icon.png \
    ../../instagram/Save-as-icon.png \
    ../../instagram/Copy.png \
    ../../instagram/paste.png \
    ../../instagram/document_add.png \
    ../../instagram/Actions-help-about-icon.png


# Location of SMTP Library
SMTP_LIBRARY_LOCATION = C:\Users\Yassine\Desktop\build_smtp_client

win32:CONFIG(release, debug|release): LIBS += -L$$SMTP_LIBRARY_LOCATION/release/ -lSMTPEmail
else:win32:CONFIG(debug, debug|release): LIBS += -L$$SMTP_LIBRARY_LOCATION/debug/ -lSMTPEmail
else:unix: LIBS += -L$$SMTP_LIBRARY_LOCATION -lSMTPEmail

INCLUDEPATH += $$SMTP_LIBRARY_LOCATION
DEPENDPATH += $$SMTP_LIBRARY_LOCATION
INCLUDEPATH += ../../../include

LIBS += -L$$OUT_PWD/../../../lib
