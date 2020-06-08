QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++1z

TARGET = summer-exam-oop
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include\
            include/HashTables\
            include/LinkedLists\
            include/Sorts\
            include/Subjects\
            include/Trees

SOURCES += \
        gui/main.cpp \
        gui/mainwindow.cpp\


HEADERS += \
        gui/mainwindow.hpp\
        include/AllExam.hpp\
        include/Map.hpp\
        include/Set.hpp\
        include/Random.hpp\



FORMS += \
        gui/mainwindow.ui

RESOURCES += \
    gui/img.qrc
