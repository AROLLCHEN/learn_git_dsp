/*
// TI File $Revision: /main/3 $
// Checkin $Date: July 9, 2008   14:12:45 $
//###########################################################################
//
// FILE:    28335_RAM_lnk.cmd
//
// TITLE:   Linker Command File For IQmath examples that run out of RAM
//
// NOTE; The example project uses memory protected by the
//       Code Security Module (CSM).  Make sure the CSM is
//       unlocked before you load the project.  One quick way
//       to do this on an erased device is to open a memory
//       window to the CSM password locations.  If these locations
//       read back 0xFFFF (or non-zero), then the CSM is unlocked:
//
//      Device    Password locations
//      28335:    0x33FFF8 - 0x33FFFF
//
//###########################################################################
//
//
// $Copyright: Copyright (C) 2014-2022 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################
*/




MEMORY
{
PAGE 0 :
   BEGIN      : origin = 0x000000, length = 0x000002     /* Boot to M0 will go here                      */
   BOOT_RSVD  : origin = 0x000002, length = 0x00004E     /* Part of M0, BOOT rom will use this for stack */

   RAML0      : origin = 0x008000, length = 0x000800
   RAML1L2    : origin = 0x008800, length = 0x004800
   ZONE7A     : origin = 0x200000, length = 0x00FC00    /* XINTF zone 7 - program space */

   FLASHH     : origin = 0x300000, length = 0x008000     /* on-chip FLASH */
   FLASHG     : origin = 0x308000, length = 0x008000     /* on-chip FLASH */
   FLASHF     : origin = 0x310000, length = 0x008000     /* on-chip FLASH */
   FLASHE     : origin = 0x318000, length = 0x008000     /* on-chip FLASH */
   FLASHD     : origin = 0x320000, length = 0x008000     /* on-chip FLASH */
   FLASHC     : origin = 0x328000, length = 0x008000     /* on-chip FLASH */
   FLASHA     : origin = 0x338000, length = 0x007F80     /* on-chip FLASH */


   CSM_RSVD   : origin = 0x33FF80, length = 0x000076     /* Part of FLASHA.  Program with all 0x0000 when CSM is in use. */
   CSM_PWL    : origin = 0x33FFF8, length = 0x000008     /* Part of FLASHA.  CSM password locations in FLASHA            */
   OTP         : origin = 0x380400, length = 0x000400     /* on-chip OTP */
   ADC_CAL    : origin = 0x380080, length = 0x000009

   IQTABLES    : origin = 0x3FE000, length = 0x000b50     /* IQ Math Tables in Boot ROM */
   IQTABLES2   : origin = 0x3FEB50, length = 0x00008c     /* IQ Math Tables in Boot ROM */
   FPUTABLES   : origin = 0x3FEBDC, length = 0x0006A0     /* FPU Tables in Boot ROM */
   ROM         : origin = 0x3FF27C, length = 0x000D44     /* Boot ROM */

   RESET      : origin = 0x3FFFC0, length = 0x000002
   VECTORS     : origin = 0x3FFFC2, length = 0x00003E     /* part of boot ROM  */







PAGE 1 :
   BOOT_RSVD  : origin = 0x000002, length = 0x00004E     /* Part of M0, BOOT rom will use this for stack */
   RAMM0      : origin = 0x000050, length = 0x0003B0     /* on-chip RAM block M0 */
   RAMM1      : origin = 0x000400, length = 0x000400     /* on-chip RAM block M1 */
   RAML3      : origin = 0x00D000, length = 0x001000
   RAML4      : origin = 0x00E000, length = 0x001000
   RAML5      : origin = 0x00F000, length = 0x001000
   ZONE7B     : origin = 0x20FC00, length = 0x000400     /* XINTF zone 7 - data space */
   FLASHB     : origin = 0x330000, length = 0x008000     /* on-chip FLASH */

}
 

SECTIONS
{
   FPUmathTables    : > FPUTABLES, PAGE = 0, TYPE = NOLOAD
   /* Setup for "boot to SARAM" mode:
      The codestart section (found in DSP28_CodeStartBranch.asm)
      re-directs execution to the start of user code.  */

   codestart        : > BEGIN,     PAGE = 0
 
#ifdef __TI_COMPILER_VERSION__
    #if __TI_COMPILER_VERSION__ >= 15009000
        .TI.ramfunc : {} LOAD = RAML0,
                         RUN = RAML0,
                         LOAD_START(_RamfuncsLoadStart),
                         LOAD_END(_RamfuncsLoadEnd),
                         RUN_START(_RamfuncsRunStart),
                         LOAD_SIZE(_RamfuncsLoadSize),
                         PAGE = 0
    #else
        ramfuncs       : LOAD = RAML0,
                         RUN = RAML0,
                         LOAD_START(_RamfuncsLoadStart),
                         LOAD_END(_RamfuncsLoadEnd),
                         RUN_START(_RamfuncsRunStart),
                         LOAD_SIZE(_RamfuncsLoadSize),
                         PAGE = 0
    #endif
#endif

	.text           : {*(.text)}>> RAML1L2|RAML0 PAGE = 0
	.cinit          : > RAML0,     PAGE = 0
    .pinit           : > RAML0,     PAGE = 0
    .switch          : > RAML0,     PAGE = 0

    .stack           : > RAMM1,     PAGE = 1
    .ebss            : > RAML3,     PAGE = 1
    .econst          : > RAML3,     PAGE = 1
    .sysmem          : > RAML3,     PAGE = 1
    .esysmem         : > RAML3,     PAGE = 1

    .sysmem          : > RAML3,     PAGE = 1

	FIR_buffer0		: > RAML4,     PAGE = 1
	FIR_buffer1		: > RAML5,     PAGE = 1


   .cio             : > RAML3,     PAGE = 1
   ZONE7DATA        : > ZONE7B,    PAGE = 1

   DMARAML4         : > RAML4,     PAGE = 1
   DMARAML5         : > RAML5,     PAGE = 1

   .reset           : > RESET,     PAGE = 0, TYPE = DSECT /* not used                    */
   csm_rsvd         : > CSM_RSVD   PAGE = 0, TYPE = DSECT /* not used for SARAM examples */
   csmpasswds       : > CSM_PWL    PAGE = 0, TYPE = DSECT /* not used for SARAM examples */

   /* Allocate ADC_cal function (pre-programmed by factory into TI reserved memory) */
   .adc_cal     : load = ADC_CAL,   PAGE = 0, TYPE = NOLOAD

}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
