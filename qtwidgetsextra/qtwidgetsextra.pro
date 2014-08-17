TEMPLATE = lib
TARGET = $$qtLibraryTarget(QtWidgetsExtra$${QT_MAJOR_VERSION})
CONFIG *= plugin debug_and_release
DESTDIR = ../bin/designer

greaterThan(QT_MAJOR_VERSION, 4) {
    QT *= designer
} else {
 CONFIG *= designer
}

LIBS *= -L.

DEPENDPATH *= .
INCLUDEPATH *= .

#RESOURCES = qtwidgetsextra.qrc

HEADERS = QtWidgetsExtra.h \
    QEmbedableButton_p.h \
    QOpenFileButtonPlugin.h \
    QOpenFileLineEditPlugin.h \
    QOpenFolderLineEditPlugin.h

SOURCES = QtWidgetsExtra.cpp \
    QEmbedableButton.cpp \
    QOpenFileButtonPlugin.cpp \
    QOpenFileLineEditPlugin.cpp \
    QOpenFolderLineEditPlugin.cpp

include(qopenfile.pri)
include(qopenfolder.pri)

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS *= target
