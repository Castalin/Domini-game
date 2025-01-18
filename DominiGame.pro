TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "..\SFML-2.6.2\include"
DEPENDPATH += "..\SFML-2.6.2\include"


LIBS += -L"../LIBS"

CONFIG(debug  , debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-system-d -lsfml-network-d -lsfml-window-d
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window


SOURCES += \
        UI/board.cpp \
        UI/mainwindow.cpp \
        UI/sprite.cpp \
        figure.cpp \
        figurefactory.cpp \
        game.cpp \
        logicboard.cpp \
        main.cpp

DISTFILES += \
    UI/photos/black_pawn.png \
    UI/photos/board.png \
    UI/photos/bound.jpg \
    UI/photos/white_pawn.png

HEADERS += \
    UI/board.h \
    UI/boardconstants.h \
    UI/mainwindow.h \
    UI/sprite.h \
    UI/winconstants.h \
    figure.h \
    figurefactory.h \
    game.h \
    logicboard.h
