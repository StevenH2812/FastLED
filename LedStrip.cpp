/*
 * LedStrip.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: steven
 */

#include "LedStrip.h"

LedStrip::LedStrip() : _ledarray(NULL), _numleds(100), _length(100*1.67),_pixelcounter(0),_fps(30){
	_timer = millis();
}

LedStrip::LedStrip(uint16_t nleds,uint16_t ledspm,CRGB *ledarr) : _numleds(nleds), _length(nleds*100/ledspm), _pixelcounter(0),_fps(30){
	_timer = millis();
	_ledarray = ledarr;
}

void LedStrip::loopForward(CRGB color,uint16_t delay){
	if(millis()-_timer>delay){
		_timer = millis();
		setPixel(_pixelcounter,color);
		_pixelcounter==0 ? setPixel(_numleds-1,CRGB::Black) : setPixel(_pixelcounter-1,CRGB::Black);
		_pixelcounter++;
	}
	if(_pixelcounter>=_numleds){
		_pixelcounter = 0;
	}
}

void LedStrip::fill(CRGB color){
	for(uint16_t pix=0;pix<_numleds;pix++){
		_ledarray[pix] = color;
	}
}

void LedStrip::setPixel(uint16_t pix,CRGB val){
	if(!inBound(pix))
		return;
	_ledarray[pix] = val;
}

void LedStrip::setPixelR(uint16_t pix,uint8_t rval){
	if(!inBound(pix))
		return;
	_ledarray[pix].r = rval;
}

void LedStrip::setPixelG(uint16_t pix,uint8_t gval){
	if(!inBound(pix))
		return;
	_ledarray[pix].g = gval;
}

void LedStrip::setPixelB(uint16_t pix,uint8_t bval){
	if(!inBound(pix))
		return;
	_ledarray[pix].b = bval;
}

bool LedStrip::inBound(uint16_t pix){
	return (pix<_numleds && pix>=0);
}
