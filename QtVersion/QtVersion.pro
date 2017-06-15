QT += widgets
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11
QT += xml

SOURCES += \
    main.cpp \
    date.cpp \
    notesmanager.cpp \
    note.cpp \
    noteversion.cpp \
    relation.cpp \
    relationsmanager.cpp \
    mainwindow.cpp \
    trash.cpp \
    trasheditor.cpp


HEADERS += \
    date.h \
    notesmanager.h \
    note.h \
    noteversion.h \
    relation.h \
    relationsmanager.h \
    mainwindow.h \
    trasheditor.h \
    trash.h


FORMS += \
    mainwindow.ui \
    formnote.ui \
    typenote.ui \
    formrelation.ui \
    listversions.ui
