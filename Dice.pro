TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Dice.cpp \
        Player.cpp \
        SpecialDice.cpp \
        main.cpp

HEADERS += \
    Dice.h \
    Player.h \
    SpecialDice.h
