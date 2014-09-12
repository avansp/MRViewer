#-------------------------------------------------
#
# Project created by QtCreator 2014-09-12T03:19:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MRViewer
TEMPLATE = app

CONFIG -= app_bundle

SOURCES += main.cpp\
        mainwindow.cpp \
        QGraphicsImageView.cpp

HEADERS  += mainwindow.h \
    QGraphicsImageView.h

FORMS    += mainwindow.ui
