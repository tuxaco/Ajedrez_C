################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Coordenada.o 

CC_SRCS += \
../Coordenada.cc \
../Pieza.cc \
../Tablero.cc \
../ajedrez.cc 

OBJS += \
./Coordenada.o \
./Pieza.o \
./Tablero.o \
./ajedrez.o 

CC_DEPS += \
./Coordenada.d \
./Pieza.d \
./Tablero.d \
./ajedrez.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


