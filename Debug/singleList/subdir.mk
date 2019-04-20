################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../singleList/singleList.cpp 

OBJS += \
./singleList/singleList.o 

CPP_DEPS += \
./singleList/singleList.d 


# Each subdirectory must supply rules for building sources it contributes
singleList/%.o: ../singleList/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


