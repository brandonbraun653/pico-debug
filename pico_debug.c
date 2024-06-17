/******************************************************************************
 *  File Name:
 *    pico_debug.c
 *
 *  Description:
 *    Implementation of the debugging utilities for the RP2040 Pico SDK
 *
 *  2024 | Brandon Braun | brandonbraun653@protonmail.com
 *****************************************************************************/

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include "pico_debug.h"
#include "tusb.h"
#include "DAP.h"
#include "DAP_config.h"
#include "pico/stdlib.h"
#include "hardware/pll.h"
#include "hardware/clocks.h"
#include "hardware/structs/pll.h"
#include "hardware/structs/clocks.h"
#include "hardware/resets.h"


/*-----------------------------------------------------------------------------
Public Functions
-----------------------------------------------------------------------------*/

void pico_debug_configure_clocks( void )
{
  /*---------------------------------------------------------------------------
  This clock configuration is mirrored in the DAP_config.h file. Make sure it's
  consistent between the two locations.
  ---------------------------------------------------------------------------*/
  if (CPU_CLOCK != (48 * MHZ))
  {
    panic("CPU clock must be 48MHz for USB operation");
  }

  /*---------------------------------------------------------------------------
  Switch the system clock to use the USB PLL
  ---------------------------------------------------------------------------*/
  clock_configure(clk_sys,
                  CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX,
                  CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_USB,
                  48 * MHZ,
                  48 * MHZ);

  pll_deinit(pll_sys);

  /*---------------------------------------------------------------------------
  Configure the peripheral clocks to use the USB PLL
  ---------------------------------------------------------------------------*/
  clock_configure(clk_peri,
                  0,
                  CLOCKS_CLK_PERI_CTRL_AUXSRC_VALUE_CLK_SYS,
                  48 * MHZ,
                  48 * MHZ);
}

void pico_debug_init( void )
{

  DAP_Setup();
  tusb_init();

}


void pico_debug_core_x_thread()
{
  while( 1 )
  {
    tud_task(); // tinyusb device task
  }
}
