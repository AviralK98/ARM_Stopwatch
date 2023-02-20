/*
 * ini.h
 *
 *Header file code for initializing functions and variables that will
 *be governing the code flow.
 *
 *  Created on: 21 Mar 2022
 *      Author: Aviral
 */



#define initialise_variables_


// Function variables used to identify the pressed key.

	unsigned int last_pressed = 0;	 // state of the last pressed key.
	unsigned int n_press; 		 	 // state of the currently pressed key.



// Initializing pointer for the keys so that the 4-bit address of the 4 keys will change in accordance with the key pressed.

		volatile unsigned int *pointer_kEY = (unsigned int *) 0xFF200050;



		// Initializing variables for denoting hours, minutes, seconds and mili seconds.


					int h 			  = 0; 	// for hour.
					int mins		  = 0; 	// for minutes.
					int sec 		  = 0; 	// for seconds.
					int ms  		  = 0;  // for mili seconds.
					int hour_counter  = 1; 	// for counting hours, '1' for minutes and '0' for hours. Initially set to high since minutes are counted first.




// Initializing the function for toggling the 7-Segment Display.

					void set_segment (); // Setting the values of the 7-Segment display.

// Initilazing the function to control the high or low values that will turn on or off the display to give a blinking effect.

					void unset_segment (); // will set the values of the display as high or low for every minutes counted.

