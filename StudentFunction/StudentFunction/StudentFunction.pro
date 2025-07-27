TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    AddStudent.cpp \
    CalculateScore.cpp \
    ChangeInformation.cpp \
    DeleteStudent.cpp \
    main.cpp \
    ShowStudent.cpp \
    StudentScoreSummary.cpp

HEADERS += \
    AddStudent.h \
    CalculateScore.h \
    ChangeInformation.h \
    DeleteStudent.h \
    header.h \
    ShowStudent.h \
    StudentScoreSummary.h \
    StudentStruct.h
CONFIG += C++11
