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
    trash.cpp \
    trasheditor.cpp \
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
    trasheditor.h \
    trash.h \
    noteseditor.h \

FORMS += \
    mainwindow.ui \
    formnote.ui
