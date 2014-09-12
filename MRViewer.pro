#-------------------------------------------------
#
# Project created by QtCreator 2014-09-12T03:19:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MRViewer
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    QGraphicsDICOMView.cpp

HEADERS  += mainwindow.h \
    QGraphicsDICOMView.h

FORMS    += mainwindow.ui
