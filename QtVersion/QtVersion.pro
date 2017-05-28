QT += widgets
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11
QT += xml

SOURCES += \
    plurinotes.cpp \
    main.cpp \
    date.cpp \
    notesmanager.cpp \
    note.cpp \
    noteversion.cpp \
    relation.cpp \
    relationsmanager.cpp

HEADERS += \
    plurinotes.h \
    date.h \
    notesmanager.h \
    note.h \
    noteversion.h \
    relation.h \
    relationsmanager.h


