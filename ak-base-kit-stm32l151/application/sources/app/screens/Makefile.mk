CFLAGS		+= -I./sources/app/screens
CPPFLAGS	+= -I./sources/app/screens

VPATH += sources/app/screens

# CPP source files
SOURCES_CPP += sources/app/screens/scr_idle.cpp
SOURCES_CPP += sources/app/screens/scr_info.cpp
SOURCES_CPP += sources/app/screens/scr_startup.cpp
SOURCES_CPP += sources/app/screens/scr_light.cpp
SOURCES_CPP += sources/app/screens/scr_motor.cpp
SOURCES_CPP += sources/app/screens/scr_pump.cpp
SOURCES_CPP += sources/app/screens/bitmaps.cpp