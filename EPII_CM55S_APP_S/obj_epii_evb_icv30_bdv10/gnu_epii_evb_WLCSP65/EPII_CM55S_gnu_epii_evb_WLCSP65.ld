MEMORY
{
  CM55S_S_APP_ROM (rwx) : ORIGIN = 0x36000000, LENGTH = 0x60000
}
__HEAP_SIZE = 0x2000;
__STACK_SIZE = 0x4000;
ENTRY(Reset_Handler)
SECTIONS
{
    .table : ALIGN(4)
    {
        FILL(0xff)
        __vectors_start__ = ABSOLUTE(.) ;
        KEEP(*(.vectors))
        . = ALIGN(4) ;
        *(.after_vectors*)
        . = ALIGN(32);
        __privileged_functions_start__ = .;
        *(privileged_functions)
        *(privileged_functions*)
        . = ALIGN(32);
        __privileged_functions_end__ = (. - 1);
        . = ALIGN(32);
        __syscalls_flash_start__ = .;
        *(freertos_system_calls)
        *(freertos_system_calls*)
        . = ALIGN(32);
        __syscalls_flash_end__ = (. - 1);
        __unprivileged_flash_start__ = .;
    } > CM55S_S_APP_ROM
    .text : ALIGN(4)
    {
       *(.text*)
       KEEP(*freertos*/tasks.o(.rodata*))
       . = ALIGN(4);
       KEEP(*(.init))
       KEEP(*(.fini));
     *crtbegin.o(.ctors)
     *crtbegin?.o(.ctors)
     *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
     *(SORT(.ctors.*))
     *(.ctors)
     *crtbegin.o(.dtors)
     *crtbegin?.o(.dtors)
     *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
     *(SORT(.dtors.*))
     *(.dtors)
        . = ALIGN(4);
        KEEP(*(.eh_frame*))
    } > CM55S_S_APP_ROM
    .rodata : ALIGN(4)
    {
        __rodata_start = .;
        *(.rodata .rodata.* .constdata .constdata.*)
        __rodata_end = .;
    } > CM55S_S_APP_ROM
    .ARM.extab : ALIGN(4)
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > CM55S_S_APP_ROM
    .ARM.exidx : ALIGN(4)
    {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > CM55S_S_APP_ROM
    .copy.table :
   {
     . = ALIGN(4);
     __copy_table_start__ = .;
        LONG(LOADADDR(.data));
        LONG( ADDR(.data));
        LONG( SIZEOF(.data)/4);
     __copy_table_end__ = .;
   } > CM55S_S_APP_ROM
   .zero.table :
   {
     . = ALIGN(4);
     __zero_table_start__ = .;
        LONG( ADDR(.bss));
        LONG( SIZEOF(.bss)/4);
     __zero_table_end__ = .;
   } > CM55S_S_APP_ROM
     . = ALIGN(32);
    __unprivileged_flash_end__ = (. - 1);
    _etext = .;
    .data : ALIGN(4)
    {
       FILL(0xff)
    __data_start__ = .;
       . = ALIGN(32);
       __privileged_sram_start__ = .;
       *(privileged_data)
       *(privileged_data*)
       . = ALIGN(32);
       __privileged_sram_end__ = (. - 1);
        *(vtable)
       *(.data)
       *(.data.*)
       . = ALIGN(4);
       PROVIDE_HIDDEN (__preinit_array_start = .);
       KEEP(*(.preinit_array))
       PROVIDE_HIDDEN (__preinit_array_end = .);
       . = ALIGN(4);
       PROVIDE_HIDDEN (__init_array_start = .);
       KEEP(*(SORT(.init_array.*)))
       KEEP(*(.init_array))
       PROVIDE_HIDDEN (__init_array_end = .);
       . = ALIGN(4);
       PROVIDE_HIDDEN (__fini_array_start = .);
       KEEP(*(SORT(.fini_array.*)))
       KEEP(*(.fini_array))
       PROVIDE_HIDDEN (__fini_array_end = .);
       KEEP(*(.jcr*))
       . = ALIGN(4) ;
     __data_end__ = .;
    } > CM55S_S_APP_ROM
  .bss :
  {
    . = ALIGN(4);
    __bss_start__ = .;
    *(.bss)
    *(.bss.*)
    *(COMMON)
    . = ALIGN(4);
    __bss_end__ = .;
  } > CM55S_S_APP_ROM
    .noinit (NOLOAD): ALIGN(4)
    {
        _noinit = .;
        PROVIDE(__start_noinit_RAM = .) ;
        PROVIDE(__start_noinit_SRAM = .) ;
        *(.noinit*)
         . = ALIGN(4) ;
        _end_noinit = .;
       PROVIDE(__end_noinit_RAM = .) ;
       PROVIDE(__end_noinit_SRAM = .) ;
    } > CM55S_S_APP_ROM
   .heap (COPY) :
   {
     . = ALIGN(8);
     __HeapBase = .;
     PROVIDE(__HeapBase = .);
     end = __HeapBase;
     . = . + __HEAP_SIZE;
     . = ALIGN(8);
     __HeapLimit = .;
     PROVIDE(__HeapLimit = .);
   } > CM55S_S_APP_ROM
   .stack (ORIGIN(CM55S_S_APP_ROM) + LENGTH(CM55S_S_APP_ROM) - __STACK_SIZE) (COPY) :
   {
     . = ALIGN(8);
     __StackLimit = .;
     PROVIDE(__StackLimit = .);
     . = . + __STACK_SIZE;
     . = ALIGN(8);
     __StackTop = .;
     PROVIDE(__StackTop = .);
   } > CM55S_S_APP_ROM
   PROVIDE(__stack = __StackTop);
   ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")
    _image_start = LOADADDR(.text);
    _image_end = LOADADDR(.data) + SIZEOF(.data);
    _image_size = _image_end - _image_start;
}
