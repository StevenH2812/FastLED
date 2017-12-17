/*
 * LedSquare.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: steven
 */


#include "LedRectangle.h"

LedRectangle::LedRectangle() : _sideledsarr(NULL){

}

LedRectangle::LedRectangle(uint16_t nleds, uint16_t ledspm, CRGB *ledarr, uint16_t *sideledsarr) : LedStrip(nleds,ledspm,ledarr),
	_left(sideledsarr[0],ledspm,&ledarr[0]),_top(sideledsarr[1],ledspm,&ledarr[0+sideledsarr[0]]),
	_right(sideledsarr[2],ledspm,&ledarr[0+sideledsarr[0]+sideledsarr[1]]),
	_bottom(sideledsarr[3],ledspm,&ledarr[0+sideledsarr[0]+sideledsarr[1]+sideledsarr[2]])
	{
	_sideledsarr = sideledsarr;
}

