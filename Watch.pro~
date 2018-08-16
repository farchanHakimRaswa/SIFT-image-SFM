#-------------------------------------------------
#
# Project created by QtCreator 2018-06-20T18:38:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Watch
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagedir.cpp \
    sfm.cpp

HEADERS  += mainwindow.h \
    imagedir.h \
    sfm.h

FORMS    += mainwindow.ui

CONFIG += c++11

INCLUDEPATH += /usr/local/include/opencv

LIBS += -I/usr/include/eigen3 -L/usr/local/lib  -I/usr/include/opencv -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_features2d -lopencv_calib3d -lopencv_imgcodecs -lgtsam -lboost_system -ltbb 
