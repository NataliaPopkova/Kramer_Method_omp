TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        gauss.cpp \
        main.cpp

HEADERS += \
    gauss.hpp

QMAKE_LFLAGS += -fopenmp -lgomp
QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp

#LIBS += "-LC:/Program Files/Microsoft Visual Studio 10.0/libraries/librtf-0.0.3" -lrtf
#add_executable(TestCppOptParse main.cpp thirdparty/cpp-optparse/OptionParser.cpp)


