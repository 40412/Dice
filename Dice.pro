TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dice.cpp \
        game.cpp \
        main.cpp \
        player.cpp \
        special_dice.cpp

HEADERS += \
    dice.h \
    game.h \
    player.h \
    special_dice.h
