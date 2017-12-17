/*
 * StevenLeds.h
 *
 *  Created on: Nov 5, 2017
 *      Author: steven
 */

#ifndef STEVENLEDS_H_
#define STEVENLEDS_H_

#include "FastLED.h"

FASTLED_NAMESPACE_BEGIN


void ledTrail(CRGB* leds, uint16_t num_leds, uint16_t waittime, uint8_t brightness, uint16_t taillength, uint32_t color);
void musicLevelShow(CRGB* leds,uint16_t num_leds, int soundLevel);


#endif /* STEVENLEDS_H_ */
