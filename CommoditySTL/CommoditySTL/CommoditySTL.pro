TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    commodity.cpp \
    commoditymanage.cpp \
    function.cpp \
    main.cpp \
    normalcommodity.cpp \
    overseacommodity.cpp

HEADERS += \
    commodity.h \
    commoditymanage.h \
    function.h \
    normalcommodity.h \
    overseacommodity.h

CONFIG += C++11
