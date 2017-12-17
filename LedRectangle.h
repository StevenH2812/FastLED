/*
 * LedSquare.h
 *
 *  Created on: Nov 24, 2017
 *      Author: steven
 */

#ifndef LEDRECTANGLE_H_
#define LEDRECTANGLE_H_

#include "LedStrip.h"

/*
 * LedRectangle - Class that abstracts a rectangularly shaped led strip into a convenient class
 * that has knowledge of parameters such as the number of leds, the corner points of the rectangle, etc.
 * 	inputs:
 * 		nleds - number of leds
 * 		ledarr - pointer to a CRGB array of size nleds
 * 		sideledsarr - pointer to an array that contains 4 numbers, indicating the number of leds in each
 * 			side of the rectangle, starting from the left side (clockwise). For my TV it is {32,59,33,58}
 */
class LedRectangle : LedStrip{
public:
	LedRectangle();
	LedRectangle(uint16_t nleds, uint16_t ledspm, CRGB *ledarr, uint16_t *_sideledsarr);


	/*
	 *************************************************************************************************
	 ************************************     Get functions     **************************************
	 *************************************************************************************************
	 */
	inline LedStrip* getLeft(){ return &_left;};
	inline LedStrip* getRight(){return &_right;};
	inline LedStrip* getTop(){return &_top;};
	inline LedStrip* getBottom(){return &_bottom;};



protected:
	uint16_t *_sideledsarr; // Array that gives the number of leds each side of the rectangle has: left, top, right, bottom
	LedStrip _left, _right, _top, _bottom; // Each side of the rectangle is represented as an individual LedStrip
};



#endif /* LEDRECTANGLE_H_ */
