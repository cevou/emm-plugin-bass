DEFINES += BASS_LIBRARY

SOURCES += \
    bassplugin.cpp

HEADERS += \
    bass_global.h \
    bassplugin.h

EMM_SOURCE_TREE = "../emm"
EMM_BUILD_TREE = "../build-emm-Desktop_Qt_5_9_2_GCC_64bit-Debug"

include(../emm/emmplugin.pri)

DISTFILES += \
    README.md \
    LICENSE
