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
        UI/UIboard.cpp \
        UI/endgame.cpp \
        UI/mainwindow.cpp \
        UI/menu.cpp \
        UI/sprite.cpp \
        abstarct/a_window.cpp \
        abstarct/i_findoptimal.cpp \
        abstarct/i_handleinput.cpp \
        abstarct/i_window.cpp \
        logic/ai.cpp \
        logic/figure.cpp \
        logic/figurefactory.cpp \
        logic/game.cpp \
        abstarct/casualboard.cpp \
        abstarct/i_checkcell.cpp \
        logic/logicboard.cpp \
        main.cpp

DISTFILES += \
    UI/other/Verdana.ttf \
    UI/other/black_pawn.png \
    UI/other/board.png \
    UI/other/bound.jpg \
    UI/other/white_pawn.png

HEADERS += \
    UI/UIboard.h \
    UI/endgame.h \
    UI/mainwindow.h \
    UI/menu.h \
    UI/sprite.h \
    UI/winconstants.h \
    abstarct/a_window.h \
    abstarct/i_findoptimal.h \
    abstarct/i_handleinput.h \
    abstarct/i_window.h \
    logic/ai.h \
    logic/figure.h \
    logic/figurefactory.h \
    logic/game.h \
    abstarct//casualboard.h \
    abstarct/i_checkcell.h \
    logic/logicboard.h
