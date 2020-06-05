TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_LFLAGS += -static

SOURCES += \
        essauwilliams.cpp \
        func.cpp \
        main.cpp

HEADERS += \
    essauwilliams.h \
    func.h

