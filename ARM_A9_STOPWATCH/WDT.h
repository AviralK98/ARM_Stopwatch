/*
 * WDT.h
 * This code resets the watchdog and returns the watchdog's timer value at the moment
 * when it is reseted.
 *  Created on: 21 Mar 2022
 *      Author: Aviral
 */

#define W_Timer_
//defining the functions for resetting the watchdog timer and resetting the timer.
#define timer_reset() WDT_reset()


__forceinline static void WDT_reset() // Resetting the watchdog timer.

	{
		*((volatile unsigned int *) 0xFFD0200C) = 0x76; // Value used to reset the watchdog timer.
	}

__forceinline static unsigned int WDT_value() // Function to get value of the watchdog timer.

{
		return *((volatile unsigned int *) 0xFFD02008);

}
