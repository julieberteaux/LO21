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
    relationsmanager.cpp \
    mainwindow.cpp \
    noteseditor.cpp \
    trash.cpp \
    formnote.cpp \
    formversion.cpp

    trash.cpp

    noteseditor.cpp


HEADERS += \
    plurinotes.h \
    date.h \
    notesmanager.h \
    note.h \
    noteversion.h \
    relation.h \
    relationsmanager.h \
    mainwindow.h \
    noteseditor.h \
    trash.h \
    formnote.h \
    formversion.h

    trash.h
    noteseditor.h

FORMS += \
    mainwindow.ui \
    formnote.ui
