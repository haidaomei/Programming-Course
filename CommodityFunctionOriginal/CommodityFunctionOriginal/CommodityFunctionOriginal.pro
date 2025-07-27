TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    data.cpp \
    function.cpp \
    help.cpp \
    main.cpp

HEADERS += \
    data.h \
    datatype.h \
    function.h \
    header.h \
    help.h

CONFIG += C++11
