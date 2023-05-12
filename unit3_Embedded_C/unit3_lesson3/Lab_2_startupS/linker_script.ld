/* linker_script.ld for cortexM3 */ 
/* Eng : Ahmedalaalotfy */ 


MEMORY 
{
	flash(RX) : ORIGIN = 0x08000000 , LENGTH = 128K 
	sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 20K
} 

SECTIONS
{
	
    .text : 
    {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _E_text = . ;
    }> flash

    .data :
    {
    _S_DATA = . ;
        *(.data)
    _E_DATA = . ;   
    }> sram AT> flash

    .bss :
    {
    _S_bss = . ;
        *(.bss)
    _E_bss = . ;    
    }> sram

}