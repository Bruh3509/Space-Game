QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ammo.cpp \
    asteroid.cpp \
    bullet.cpp \
    glider.cpp \
    incomingobject.cpp \
    main.cpp \
    mainwindow.cpp \
    movingmonster.cpp \
    mygraphicsscene.cpp \
    ufo.cpp \
    ufobullet.cpp

HEADERS += \
    ammo.h \
    asteroid.h \
    bullet.h \
    glider.h \
    incomingobject.h \
    mainwindow.h \
    movingmonster.h \
    mygraphicsscene.h \
    ufo.h \
    ufobullet.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
