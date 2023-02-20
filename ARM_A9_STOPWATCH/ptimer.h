/*
 * ptimer.h
 *
 * Initializing the A-9 Private Timer.
 *
 *  Created on: 21 Mar 2022
 *      Author: Aviral
 */


#define A_NINE_H_

// Initializing the A-9 Private Timer.

		void ini_nine( signed int load_value );

// Initilaizing the Interrupt Flag.

			unsigned int stat_int() ;

// Resetting the private timer.

					void int_reset ();

 /* A_NINE_H_ */
