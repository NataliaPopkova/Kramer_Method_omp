TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        kramer.cpp \
        main.cpp

HEADERS += \
    kramer.hpp

QMAKE_LFLAGS += -fopenmp -lgomp
QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp

