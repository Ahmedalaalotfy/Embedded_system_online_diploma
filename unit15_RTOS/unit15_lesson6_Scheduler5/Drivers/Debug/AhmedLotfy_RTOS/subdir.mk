################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AhmedLotfy_RTOS/CortexMX_OS_porting.c \
../AhmedLotfy_RTOS/MYRTOS_FIFO.c \
../AhmedLotfy_RTOS/Scheduler.c 

OBJS += \
./AhmedLotfy_RTOS/CortexMX_OS_porting.o \
./AhmedLotfy_RTOS/MYRTOS_FIFO.o \
./AhmedLotfy_RTOS/Scheduler.o 

C_DEPS += \
./AhmedLotfy_RTOS/CortexMX_OS_porting.d \
./AhmedLotfy_RTOS/MYRTOS_FIFO.d \
./AhmedLotfy_RTOS/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
AhmedLotfy_RTOS/CortexMX_OS_porting.o: ../AhmedLotfy_RTOS/CortexMX_OS_porting.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/AhmedLotfy_RTOS/inc" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/CMSIS_v5" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/EEPROM" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/I2C" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/SPI" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/USART" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/RCC" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/EXTI" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/GPIO" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/KPD_Driver" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/LCD_Driver" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"AhmedLotfy_RTOS/CortexMX_OS_porting.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
AhmedLotfy_RTOS/MYRTOS_FIFO.o: ../AhmedLotfy_RTOS/MYRTOS_FIFO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/AhmedLotfy_RTOS/inc" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/CMSIS_v5" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/EEPROM" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/I2C" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/SPI" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/USART" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/RCC" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/EXTI" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/GPIO" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/KPD_Driver" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/LCD_Driver" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"AhmedLotfy_RTOS/MYRTOS_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
AhmedLotfy_RTOS/Scheduler.o: ../AhmedLotfy_RTOS/Scheduler.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/AhmedLotfy_RTOS/inc" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/CMSIS_v5" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/EEPROM" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/I2C" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/SPI" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/USART" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/RCC" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/EXTI" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCAL/GPIO" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/KPD_Driver" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/HAL/LCD_Driver" -I"C:/Users/ahmed/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"AhmedLotfy_RTOS/Scheduler.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

