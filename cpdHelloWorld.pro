TEMPLATE = app
TARGET = cpdHelloWorld
CONFIG += c++14
QT += widgets printsupport

CPD_LIB_PATH = ../common-print-dialog
#QMAKE_CXXFLAGS += -rpath=$$absolute_path($$CPD_LIB_PATH)
QMAKE_LFLAGS = -Wl,-rpath,$$absolute_path($$CPD_LIB_PATH)
LIBS += -L$$CPD_LIB_PATH -lcpd
DEPENDPATH += $$CPD_LIB_PATH
INCLUDEPATH += $${DEPENDPATH}

SOURCES += main.cpp
