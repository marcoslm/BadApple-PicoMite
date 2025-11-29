/* Script mínimo para CSUBs de PicoMite */

MEMORY
{
    rom (rx) : ORIGIN = 0x00000000, LENGTH = 0x00010000
}

SECTIONS
{
    .text :
    {
        *(.text*)
        *(.rodata*)
        *(.data*)
        *(.bss*)
    } > rom
}
