################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/StanfordCPPLib/stacktrace/call_stack_gcc.cpp \
../lib/StanfordCPPLib/stacktrace/call_stack_windows.cpp 

OBJS += \
./lib/StanfordCPPLib/stacktrace/call_stack_gcc.o \
./lib/StanfordCPPLib/stacktrace/call_stack_windows.o 

CPP_DEPS += \
./lib/StanfordCPPLib/stacktrace/call_stack_gcc.d \
./lib/StanfordCPPLib/stacktrace/call_stack_windows.d 


# Each subdirectory must supply rules for building sources it contributes
lib/StanfordCPPLib/stacktrace/%.o: ../lib/StanfordCPPLib/stacktrace/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


