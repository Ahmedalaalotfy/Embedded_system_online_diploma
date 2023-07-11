# @Ahmedalaalotfy 
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.S)
AsOBJ= $(As:.s=.o)
Project_name=ahmed_cortexM3

all: $(Project_name).bin
	@echo "========Build is done========" 		
	


%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@ 

$(ProjectName).hex:$(ProjectName).elf
	$(CC)objcopy.exe -O ihex $< $@

clean_all: 
	rm *.o *.elf *.bin	
	
clean: 
	rm *.elf *.bin	
	