QT += widgets
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11
QT += xml

SOURCES += \
    plurinotes.cpp \
    main.cpp \
    date.cpp

HEADERS += \
    plurinotes.h \
    date.h
