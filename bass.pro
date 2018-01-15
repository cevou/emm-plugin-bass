DEFINES += BASS_LIBRARY

QT += widgets

LIBS += -lbass -L$$PWD/external
INCLUDEPATH += $$PWD/headers

SOURCES += \
    bassplugin.cpp \
    bassdriver.cpp \
    bassdevice.cpp \
    bassworker.cpp \
    basschannel.cpp \
    settingspage.cpp \
    bassstream.cpp

HEADERS += \
    bass_global.h \
    bassplugin.h \
    bassdriver.h \
    bassdevice.h \
    bassworker.h \
    basschannel.h \
    settingspage.h \
    settingsfactory.h \
    bassstream.h

EMM_SOURCE_TREE = "../emm"

include(../emm/emmplugin.pri)

DISTFILES += \
    bass.json

OTHER_FILES += \
    README.md \
    LICENSE

FORMS += \
    settingspage.ui
