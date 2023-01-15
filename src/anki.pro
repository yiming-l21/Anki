#-------------------------------------------------
#
# Project created by QtCreator 2022-03-05T10:29:53
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
QT       += sql widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = anki
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    helpmanual.cpp \
    createcardset.cpp \
    exportdia.cpp \
    button.cpp \
    labels.cpp \
    append.cpp \
    global.cpp \
    selectdeck.cpp \
    mytableview.cpp \
    renamedeck.cpp \
    importdia.cpp \
    selectstudy.cpp \
    editcard.cpp \
    studyplan.cpp \
    browse.cpp \
    statics.cpp

HEADERS  += mainwindow.h \
    helpmanual.h \
    createcardset.h \
    exportdia.h \
    button.h \
    labels.h \
    card.h \
    append.h \
    decks.h \
    global.h \
    selectdeck.h \
    mytableview.h \
    renamedeck.h \
    importdia.h \
    selectstudy.h \
    editcard.h \
    studyplan.h \
    browse.h \
    statics.h

FORMS    += mainwindow.ui \
    helpmanual.ui \
    createcardset.ui \
    exportdia.ui \
    append.ui \
    selectdeck.ui \
    renamedeck.ui \
    importdia.ui \
    selectstudy.ui \
    editcard.ui \
    studyplan.ui \
    browse.ui \
    statics.ui

RESOURCES += \
    myimages.qrc \
    images.qrc

DISTFILES +=
