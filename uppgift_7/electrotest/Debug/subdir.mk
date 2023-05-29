################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libcomponent.c \
../libpower.c \
../libresistance.c \
../main.c 

C_DEPS += \
./libcomponent.d \
./libpower.d \
./libresistance.d \
./main.d 

OBJS += \
./libcomponent.o \
./libpower.o \
./libresistance.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./libcomponent.d ./libcomponent.o ./libpower.d ./libpower.o ./libresistance.d ./libresistance.o ./main.d ./main.o

.PHONY: clean--2e-

