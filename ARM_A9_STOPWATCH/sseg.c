/*
 * sseg.c
 *
 * This Code is used to implement the bit- mapping on the 7-Segment display
 * according to the code flow.
 *
 *  Created on: 21 Mar 2022
 *      Author: Aviral
 */



#include "sseg.h"

#define High_D 2 // 2 High address based displays.
#define Low_D  4 // 4 Low address based displays.


//Bit-Mapping for the 7-Segment Display.

		unsigned char mapping[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x40};







// For the display segment low; 0-4.

	volatile unsigned char *Low_Addr = (unsigned char *) 0xFF200020;

// For the display segment high; 5-6.

		volatile unsigned char *High_Addr = (unsigned char *) 0xFF200030;




		// Initializing the displays by writing the values corresponding to the base address.

		void ini_seg(unsigned int d, unsigned char v)
			{

			if	(d < Low_D ) //Condition for Lower base numbers

				{

				//Mapping them onto the display.

				Low_Addr[d] = v;

				}
			else
				{
					//Condition for higher base numbers

					d = d - Low_D;

					//Mapping them onto the display.

					High_Addr[d] = v;
				}

		}

		// Initializing the Single Display

			void one_seg(unsigned int d, unsigned int v)

				{


					if( v > 10 )

						{ 	// Condition satisfied the display is set to low '0'.

							ini_seg (d, 0);

						}

					else

						{
							// Condition for mapping the single display.

							ini_seg ( d, mapping[v] );
						}



				}

		//Initializing the Double Displays.

			void two_seg (unsigned int d, unsigned int v)

			{



			if(v > 10)

				{  // For incrementing the count and enabling the second display to display a double-digit number.

				// Display the Unit's placed digit.
				one_seg (d,(v % 10));

				// Display the Tenth's placed digit.
				one_seg (d+1,( v / 10 ) );


				}


			else

				{
							// For the mapping values 0-9

							// Display the value in the first segment.
							one_seg  (d,v);

							// Displaying '0' in the second to give the effect of a stop-watch.
							one_seg  (d+1,0);
				}


			}

