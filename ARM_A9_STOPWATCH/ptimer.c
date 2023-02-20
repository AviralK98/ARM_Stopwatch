/*
 * ptimer.c
 *
 *Configuring the A-9 Timer with the StopWatch Code.
 *
 *  Created on: 21 Mar 2022
 *      Author: Aviral
 */




#include "ptimer.h"



// For the base address of the timer.

	volatile unsigned int *base_time   = (unsigned int *)0xFFFEC600;

// Timer Address Loading.

		volatile unsigned int *load_time   = (unsigned int *)0xFFFEC600;

// Setting the Timer with the Current value.

		volatile unsigned int *val_time    = (unsigned int *)0xFFFEC604;

//Control base pointer according to the control base address.

			volatile unsigned int *ctrl_time  = (unsigned int *)0xFFFEC608;

// Setting the interrupt base address.

			volatile unsigned int *time_int = (unsigned int *)0xFFFEC60C;






// Timer Initialization

	void ini_nine ( signed int load_value )

		{
			// Setting the loaded value as the base address.

			*load_time = load_value ;

			//	Setting the pre-scalar values.

			*ctrl_time =  (1 << 1) | (1 << 0);


		}


// Interrupt is set to high when the timer counted down to zero.

	unsigned int stat_int ( )

		{

			unsigned int i_val = *time_int;
			return *time_int;

		}


// Initializing the timer to begin again.

		void int_reset ( )

			{
				// Resetting the timer by passing the base value.

				*time_int = 0x1;

			}

