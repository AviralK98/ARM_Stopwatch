/*
 * ini.c
 *
 * Code to initialize the display segments as high or low based on the code flow.
 *
 *  Created on: 21 Mar 2022
 *      Author: Aviral
 */





#include "sseg.h"


// Initializing the 7-Segment display to the initial low '0'.

			void set_segment ()

			{

				one_seg(0,0); //First Segment
				one_seg(1,0); //Second Segment
				one_seg(2,0); //Third Segment
				one_seg(3,0); //Fourth Segment
				one_seg(4,0); //Fifth Segment
				one_seg(5,0); //Sixth Segment

			}

// Initialising the first two segments as low '0' to turn them off when a minute is counted.

			void unset_segment ()

			{
				//Giving the values as 10 since it is not present in the Hex-code and therefore it will display nothing.

				one_seg(4,10);     //First Segment
				one_seg(5,10); //Second Segment

			}

