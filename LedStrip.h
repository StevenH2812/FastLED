/*
 * LedStrip.h
 *
 *  Created on: Nov 24, 2017
 *      Author: steven
 */

#ifndef LEDSTRIP_H_
#define LEDSTRIP_H_

#include "FastLED.h"

/*
 * Utility class that abstracts a ledstrip into a convenient class
 * that already has parameters defined like the length of the led strip.
 * 	inputs:
 * 		nleds - number of leds in the led strip.
 * 		ledarr - pointer to a CRGB array with nleds entries.
 */
class LedStrip{
public:
	LedStrip();
	LedStrip(uint16_t nleds,uint16_t ledspm,CRGB *ledarr);

	/*
	 *********************************************************************************************************
	 *************************************      Effects      *************************************************
	 *********************************************************************************************************
	 */

	// Loop forward over all the pixels in this strip, setting them to a certain color, waiting for a delay,
	// 	then setting it back to black and setting the next pixel to a certain color.
	//		inputs:
	//			delay - delay in milliseconds
	//			color - CRGB color to set pixel to
	void loopForward(CRGB color,uint16_t delay);

	// Fill the entire strip with one color
	//		inputs:
	//			color - CRGB color to set pixel to
	void fill(CRGB color);



	/*
	 *********************************************************************************************************
	 *************************************      Setters      *************************************************
	 *********************************************************************************************************
	 */
	void setPixel(uint16_t pix,CRGB val);
	void setPixelR(uint16_t pix,uint8_t rval);
	void setPixelG(uint16_t pix,uint8_t gval);
	void setPixelB(uint16_t pix,uint8_t bval);

	/*
	 *********************************************************************************************************
	 ***********************************      Utility functions      *****************************************
	 *********************************************************************************************************
	 */
	bool inBound(uint16_t pix);

protected:
	uint16_t _numleds;
	float _length; // [m] physical length of led array
	CRGB *_ledarray; // led array pointer
	unsigned long _timer;
	uint16_t _pixelcounter; // internally used pixelcounter
	uint8_t _fps;
};



#endif /* LEDSTRIP_H_ */
