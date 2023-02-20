/*
 * main.c
 *
 *The main part/method for the execution of the code
 *
 *  Created on: 21 Mar 2022
 *      Author: Aviral
 */




#include "ini.h"
#include "ptimer.h"
#include "sseg.h"
#include "WDT.h"


// Initializing the  timer interrupt pointer with the base address.

	volatile unsigned int *int_time_pvalue  = (unsigned int *)0xFFC08000;

// Initializing the interrupt with the base address.

	volatile unsigned int *time_int_value = (unsigned int *) 0xFFFEC60C;







	// Function used to count minutes i.e hour is zero | MM : SS : MS MS

	void minutes ()

		{


		// Timer Interrupt '1'.

		while( ( *time_int_value & 0x1 )  )

			{
				// Resetting the Interrupt
				int_reset();


				// Mili-Seconds are clocked

				ms = ms + 1;


				if(ms < 100 )

				{

				two_seg(0,ms); // Clocking Mili-Seconds.

				}

				else if(sec < 59)

					{


					if( ((sec == 60) )&& (mins > 0))

						{

							unset_segment();
							ms = 0; // Mili-Seconds are rested.
							sec = sec + 1; // Seconds are clocked.
					}
					else
						{
							ms = 0;
							sec = sec + 1;
							//Displaying on the double segments.
							two_seg(2,sec);
							two_seg(4,mins);
				}

			}
				else if(mins < 59)

					{


					unset_segment();
					sec = 0;
					ms = 0;
					mins = mins + 1; // Minutes are Clocked


			}

				else

				{
					unset_segment();
					hour_counter = 0;
					mins = 0;
					sec = 0;
					ms = 0;
					h = h + 1; // Clocking Hours
					ini_nine( 225000000 ); // For 1 second, the timer is set to reset.

			}

		}

	}

	void hour()

		{

	//  Interrupt timer is '1'.
		while	( ( *time_int_value & 0x1 )  )

				{
					// Reseting the Timer
					int_reset();

							if( sec < 59)

								{

								if(sec == 60)

								{
									// Resetting the segment with '0' to display nothing for the 60th second.

									unset_segment();
									sec = sec + 1;
								}

							else

								{
									sec = sec + 1;
									two_seg(0,sec);
									two_seg(2,mins);
									two_seg(4,h);
								}


							}

							else if(mins < 59)

								{
								    //Clocking Minutes

								// Indicating when a minute is clocked.

									unset_segment();
									sec = 0;
									mins = mins + 1;


							}

							else if (h < 99 )

								{
									// Counting Hours
									// Indicating when an hour is clocked.

									unset_segment();
									mins= 0;
									sec = 0;
									h = h + 1;


							}

							else if(h > 99)

								{

								mins = 0;
								h    = 0;
								sec= 0;
								ms = 0;
								hour_counter = 1;
								ini_nine ( 2250000 ); // Resetting the A9 timer.

							}

						}
			// Resetting the watchdog timer to prevent the system from going to idle and resetting itself and the A9 timer.
			WDT_reset();

	}
	unsigned int keypress()

		{


	    unsigned int n_press = *pointer_kEY; // find what key is pressed

	    if(  n_press != last_pressed)

	    	{

	    	// Key press did not match.

	    	last_pressed = n_press;
	    	n_press = last_pressed ;

	    	}

	    else

	    	{
	    		// Keys are not pressed.

	    		n_press = 0;

	    	}

	    return n_press;

	}



	// Function for initializing the 7-Segment Display and setting the initial conditions

	void Initialise_Seven_Segment()

		{

			// Setting the Initial conditions

			set_segment();

			ini_nine( 2250000 );

			n_press = 0;

			ms = 0;
			sec       = 0;
			h          = 0;
			mins       = 0;



	}

	// Main method to call all the declared functions.

	int main(void)

	{
		//Setting up the Initial Conditions.

		Initialise_Seven_Segment() ;
		int_time_pvalue[2] = 0;
		int_time_pvalue[0] = 100000000;
		int_time_pvalue[2] = 0x03;


		while(1)

				{

				// Checking for the keypress.

				n_press = keypress();

				// Restting the watchdog timer.

				WDT_reset();


				if (n_press & 0x4)

					{
		                // While the conditions are true.

					while(1)

						{
						// Checking for the keypress.
						n_press = keypress();

						if( !( n_press & 0x2) && !(n_press & 0x1) )

						{
							if(hour_counter == 1)

							{
								// Count Minutes
								minutes();
								WDT_reset();

							}
							else

								{

								hour();
								WDT_reset();

							}
							// Resetting timer (preventing idle)
							WDT_reset();



						}
						else

						{   // Pressed button is 2

							// while conditions are met
							while (1)

							{

								WDT_reset();

								// Checking for the keypress
								n_press = keypress();

							if( n_press & 0x4 )

							{
								// Pressed button is 1

								// Break and begin the count again
								break;

							}
							else if(n_press & 0x1)

							{
								// Pressed button is 2

								// Start from the beginning '00:00:00'
								Initialise_Seven_Segment();
								WDT_reset();

							}

						}

						}
					}
				}

			}


		}






