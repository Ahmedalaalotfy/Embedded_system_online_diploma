################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/HAL/LCD_Driver/LCD_program.c 

OBJS += \
./Stm32_F103C6_Drivers/HAL/LCD_Driver/LCD_program.o 

C_DEPS += \
./Stm32_F103C6_Drivers/HAL/LCD_Driver/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/HAL/LCD_Driver/LCD_program.o: ../Stm32_F103C6_Drivers/HAL/LCD_Driver/LCD_program.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/EXTI" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/GPIO" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/KPD_Driver" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/LCD_Driver" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/HAL/LCD_Driver/LCD_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

