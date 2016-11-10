#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := SignalControl.cpp Commands.cpp IRLed.cpp IRLedController.cpp IRSensor.cpp IRSensorController.cpp CommandsBTS.cpp CommandControl.cpp 

# header files in this project
HEADERS := SignalControl.hpp Commands.hpp IRLed.hpp IRLedController.hpp IRSensor.hpp IRSensorController.hpp CommandsBTS.hpp CommandControl.hpp Queue.hpp

# other places to look for files for this project
SEARCH  := 

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../

include $(BMPTK)Makefile.due
