# File Name: makefile
# Author: Sunny Taksande
# Date: 23 June 2011
# Purpose: make file for building uart lib

# Set appropriate paths

#INSTALLDIR     = 

PROJECTPATH 	= .
SOURCEPATH	= $(PROJECTPATH)/src
INCLUDEPATH	= $(PROJECTPATH)/include
BINPATH		= $(PROJECTPATH)/bin
LIBPATH		= $(PROJECTPATH)/lib
TARGETPATH	= $(BINPATH)

TARGETS		= 
LIBS            = $(LIBPATH)/libi2c.a 

SRCFILES 	= $(SOURCEPATH)/I2Cgpiolib.c 

DEPENDANCIES	= makefile \
		$(INCLUDEPATH)/i2c-dev.h \
		$(INCLUDEPATH)/I2Cgpiolib.h


# Compilation Flags

CC		= /media/_home/aurion/ruiva-dm355-dvsdk2/montavista/pro/devkit/arm/v5t_le/bin/arm_v5t_le-gcc

CFLAGS		= -c -I $(INCLUDEPATH) -I $(INSTALLDIR)/include

# Compilation Section

all: $(LIBS)

$(LIBPATH)/libi2c.a: $(DEPENDANCIES) $(SRCFILES)
	$(CC) $(CFLAGS) $(SRCFILES) $(INCLUDEFLAGS)
	ar rcs $@ *.o
	rm *.o

install: $(LIBS)
	install -m666 $(LIBPATH)/libi2c.a $(INSTALLDIR)/lib
	install -m666 $(INCLUDEPATH)/I2Cgpiolib.h $(INSTALLDIR)/include

# Cleaning Section

clean:
	rm -f $(LIBS)
