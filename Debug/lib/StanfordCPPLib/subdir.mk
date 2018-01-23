################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/StanfordCPPLib/base64.cpp \
../lib/StanfordCPPLib/basicgraph.cpp \
../lib/StanfordCPPLib/bitstream.cpp \
../lib/StanfordCPPLib/console.cpp \
../lib/StanfordCPPLib/dawglexicon.cpp \
../lib/StanfordCPPLib/direction.cpp \
../lib/StanfordCPPLib/error.cpp \
../lib/StanfordCPPLib/exceptions.cpp \
../lib/StanfordCPPLib/filelib.cpp \
../lib/StanfordCPPLib/gbufferedimage.cpp \
../lib/StanfordCPPLib/gevents.cpp \
../lib/StanfordCPPLib/gfilechooser.cpp \
../lib/StanfordCPPLib/ginteractors.cpp \
../lib/StanfordCPPLib/gmath.cpp \
../lib/StanfordCPPLib/gobjects.cpp \
../lib/StanfordCPPLib/goptionpane.cpp \
../lib/StanfordCPPLib/gtimer.cpp \
../lib/StanfordCPPLib/gtypes.cpp \
../lib/StanfordCPPLib/gwindow.cpp \
../lib/StanfordCPPLib/hashcode.cpp \
../lib/StanfordCPPLib/lexicon.cpp \
../lib/StanfordCPPLib/main.cpp \
../lib/StanfordCPPLib/observable.cpp \
../lib/StanfordCPPLib/platform.cpp \
../lib/StanfordCPPLib/point.cpp \
../lib/StanfordCPPLib/random.cpp \
../lib/StanfordCPPLib/regexpr.cpp \
../lib/StanfordCPPLib/shuffle.cpp \
../lib/StanfordCPPLib/simpio.cpp \
../lib/StanfordCPPLib/sound.cpp \
../lib/StanfordCPPLib/startup.cpp \
../lib/StanfordCPPLib/strlib.cpp \
../lib/StanfordCPPLib/timer.cpp \
../lib/StanfordCPPLib/tokenscanner.cpp \
../lib/StanfordCPPLib/urlstream.cpp \
../lib/StanfordCPPLib/version.cpp 

OBJS += \
./lib/StanfordCPPLib/base64.o \
./lib/StanfordCPPLib/basicgraph.o \
./lib/StanfordCPPLib/bitstream.o \
./lib/StanfordCPPLib/console.o \
./lib/StanfordCPPLib/dawglexicon.o \
./lib/StanfordCPPLib/direction.o \
./lib/StanfordCPPLib/error.o \
./lib/StanfordCPPLib/exceptions.o \
./lib/StanfordCPPLib/filelib.o \
./lib/StanfordCPPLib/gbufferedimage.o \
./lib/StanfordCPPLib/gevents.o \
./lib/StanfordCPPLib/gfilechooser.o \
./lib/StanfordCPPLib/ginteractors.o \
./lib/StanfordCPPLib/gmath.o \
./lib/StanfordCPPLib/gobjects.o \
./lib/StanfordCPPLib/goptionpane.o \
./lib/StanfordCPPLib/gtimer.o \
./lib/StanfordCPPLib/gtypes.o \
./lib/StanfordCPPLib/gwindow.o \
./lib/StanfordCPPLib/hashcode.o \
./lib/StanfordCPPLib/lexicon.o \
./lib/StanfordCPPLib/main.o \
./lib/StanfordCPPLib/observable.o \
./lib/StanfordCPPLib/platform.o \
./lib/StanfordCPPLib/point.o \
./lib/StanfordCPPLib/random.o \
./lib/StanfordCPPLib/regexpr.o \
./lib/StanfordCPPLib/shuffle.o \
./lib/StanfordCPPLib/simpio.o \
./lib/StanfordCPPLib/sound.o \
./lib/StanfordCPPLib/startup.o \
./lib/StanfordCPPLib/strlib.o \
./lib/StanfordCPPLib/timer.o \
./lib/StanfordCPPLib/tokenscanner.o \
./lib/StanfordCPPLib/urlstream.o \
./lib/StanfordCPPLib/version.o 

CPP_DEPS += \
./lib/StanfordCPPLib/base64.d \
./lib/StanfordCPPLib/basicgraph.d \
./lib/StanfordCPPLib/bitstream.d \
./lib/StanfordCPPLib/console.d \
./lib/StanfordCPPLib/dawglexicon.d \
./lib/StanfordCPPLib/direction.d \
./lib/StanfordCPPLib/error.d \
./lib/StanfordCPPLib/exceptions.d \
./lib/StanfordCPPLib/filelib.d \
./lib/StanfordCPPLib/gbufferedimage.d \
./lib/StanfordCPPLib/gevents.d \
./lib/StanfordCPPLib/gfilechooser.d \
./lib/StanfordCPPLib/ginteractors.d \
./lib/StanfordCPPLib/gmath.d \
./lib/StanfordCPPLib/gobjects.d \
./lib/StanfordCPPLib/goptionpane.d \
./lib/StanfordCPPLib/gtimer.d \
./lib/StanfordCPPLib/gtypes.d \
./lib/StanfordCPPLib/gwindow.d \
./lib/StanfordCPPLib/hashcode.d \
./lib/StanfordCPPLib/lexicon.d \
./lib/StanfordCPPLib/main.d \
./lib/StanfordCPPLib/observable.d \
./lib/StanfordCPPLib/platform.d \
./lib/StanfordCPPLib/point.d \
./lib/StanfordCPPLib/random.d \
./lib/StanfordCPPLib/regexpr.d \
./lib/StanfordCPPLib/shuffle.d \
./lib/StanfordCPPLib/simpio.d \
./lib/StanfordCPPLib/sound.d \
./lib/StanfordCPPLib/startup.d \
./lib/StanfordCPPLib/strlib.d \
./lib/StanfordCPPLib/timer.d \
./lib/StanfordCPPLib/tokenscanner.d \
./lib/StanfordCPPLib/urlstream.d \
./lib/StanfordCPPLib/version.d 


# Each subdirectory must supply rules for building sources it contributes
lib/StanfordCPPLib/%.o: ../lib/StanfordCPPLib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


