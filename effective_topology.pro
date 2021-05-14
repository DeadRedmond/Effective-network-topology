TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_LFLAGS += -static

SOURCES += \
        args.cpp \
        essauwilliams.cpp \
        func.cpp \
        gen.cpp \
        main.cpp

HEADERS += \
    args.h \
    essauwilliams.h \
    func.h \
    gen.h \
    matrix.h

