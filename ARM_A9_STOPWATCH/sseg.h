/*
 * sseg.h
 *
 *Header file to initialize the functions to control the 7-Segment Display.
 *
 *  Created on: 21 Mar 2022
 *      Author: Aviral
 */

#define SSegemnt_H_

//Function to initialize the segments.

		void ini_seg (unsigned int d , unsigned char v);

//Function to initialize a single segment.

	void one_seg(unsigned int d, unsigned int v);

//Function to initialize the double segments.

		void two_seg(unsigned int d, unsigned int v);


