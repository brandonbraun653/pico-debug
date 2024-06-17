/******************************************************************************
 *  File Name:
 *    pico_debug.h
 *
 *  Description:
 *    Debugging utilities for the RP2040 Pico SDK
 *
 *  2024 | Brandon Braun | brandonbraun653@protonmail.com
 *****************************************************************************/

#pragma once
#ifndef PICO_DEBUG_H
#define PICO_DEBUG_H

#if defined(__cplusplus)
extern "C"
{
#endif

/*-----------------------------------------------------------------------------
Public Functions
-----------------------------------------------------------------------------*/

/**
 * @brief Configure system clocks to support USB functionality.
 *
 * This will assume control of all clock configuration, so if your project needs
 * to do something special, it's best to duplicate this function and modify it
 * as needed.
 */
void pico_debug_configure_clocks( void );

/**
 * @brief Initialize resources used for the picodebug system
 */
void pico_debug_init( void );

/**
 * @brief Main thread to handle running picodebug on an RP2040 core
 *
 * Must be manually set up to run on the desired core.
 */
void pico_debug_core_x_thread();

#if defined(__cplusplus)
}
#endif
#endif  /* !PICO_DEBUG_H */
