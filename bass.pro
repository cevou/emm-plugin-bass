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
    settingspage.cpp

HEADERS += \
    bass_global.h \
    bassplugin.h \
    bassdriver.h \
    bassdevice.h \
    bassworker.h \
    basschannel.h \
    settingspage.h \
    settingsfactory.h

EMM_SOURCE_TREE = "../emm"
EMM_BUILD_TREE = "../build-emm-Desktop_Qt_5_10_0_GCC_64bit-Debug"

include(../emm/emmplugin.pri)

DISTFILES += \
    bass.json

OTHER_FILES += \
    README.md \
    LICENSE

FORMS += \
    settingspage.ui
