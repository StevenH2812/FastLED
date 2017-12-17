/*
 * StevenLeds.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: steven
 */


#include "StevenLeds.h"

void setPixelColorInterval(CRGB* leds,uint16_t num_leds,uint16_t interval,uint16_t pixel, uint8_t r, uint8_t g, uint8_t b);
void setPixelColorInterval(CRGB* leds,uint16_t num_leds,uint16_t interval,uint16_t pixel, uint32_t color);
void colorWipe(CRGB* leds, uint16_t num_leds,uint32_t c, uint8_t wait);
void theaterChase(CRGB* leds, uint16_t num_leds,uint32_t c, uint16_t wait);



void ledTrail(CRGB* leds, uint16_t num_leds,uint16_t waittime,uint8_t brightness, uint16_t taillength, uint32_t color){
	for(uint16_t i = 0; i<num_leds; i++){
		fadeToBlackBy(leds,num_leds,(uint8_t)brightness/taillength);
		leds[i] = color;
		FastLED.show();
		delay(waittime);
	}
}

void musicLevelShow(CRGB* leds,uint16_t num_leds, int soundLevel){
	int lng = 100;
	int sht = 50;
	if (soundLevel <= 8)
	  {
	    //open if 0. When there is silence a rainbow pattern runs
		uint8_t gHue = 0;

	    fill_rainbow(leds,num_leds,gHue,7);

	  }//close if 0 statement

/*
	  if (soundLevel == 1)
	  {
	    //open level 1 if statement which contains 4 randomised options

	    int level1Color = random(1, 4);//choose random number 1 - 4

	    if (level1Color == 1) //if random no 1 chosen light up pixels 1 and 2 red:
	    {

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0); // this turns on pixel 1 100% red (range runs 0 - 255) and leaves green and blue off
	      setPixelColorInterval(leds,num_leds,12,1, 255, 0, 0); //  - you get the idea
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close red random no. 1

	    else if (level1Color == 2) //if random no 2 choses show green
	    {
	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close random no. 2 green


	    else if (level1Color == 3) //run blue
	    {

	      setPixelColorInterval(leds,num_leds,12,0, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close blue

	    else if (level1Color == 4) //run yellow
	    {

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close yellow



	  }//end of if sound level 1 options


	  if (soundLevel == 2)
	  {
	    //open level 2

	    int level2Color = random(1, 5);//choose one of 5 options if sound level 2

	    if (level2Color == 1) //run red mix
	    {

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 1 red

	    else if (level2Color == 2) //run green mix
	    {
	      //open option 2

	      setPixelColorInterval(leds,num_leds,12,0, 0, 206, 209);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 206, 209);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 206, 209);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close green

	    else if (level2Color == 3) //run blue mix
	    {
	      //open option 3

	      setPixelColorInterval(leds,num_leds,12,0, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 3 blue

	    else if (level2Color == 4) //run yellow
	    {
	      //open option 4

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close yellow

	    else if (level2Color == 5)//for a bit of variation 1 in 5 of level 2 will show a pattern across whole strip:
	    {
	      //open if 5
	      setPixelColorInterval(leds,num_leds,12,0, 200, 75, 109);
	      setPixelColorInterval(leds,num_leds,12,1, 252, 203, 198);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 216, 209);
	      setPixelColorInterval(leds,num_leds,12,3, 253, 215, 130);
	      setPixelColorInterval(leds,num_leds,12,4, 181, 198, 130);
	      setPixelColorInterval(leds,num_leds,12,5, 141, 189, 193);
	      setPixelColorInterval(leds,num_leds,12,6, 177, 217, 242);
	      setPixelColorInterval(leds,num_leds,12,7, 100, 165, 187);
	      setPixelColorInterval(leds,num_leds,12,8, 133, 105, 128);
	      setPixelColorInterval(leds,num_leds,12,9, 140, 166, 95);
	      setPixelColorInterval(leds,num_leds,12,10, 198, 44, 58);
	      setPixelColorInterval(leds,num_leds,12,11, 149, 69, 103);


	      FastLED.show();
	      delay(lng);

	      setPixelColorInterval(leds,num_leds,12,1, 200, 75, 109);
	      setPixelColorInterval(leds,num_leds,12,2, 252, 203, 198);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 216, 209);
	      setPixelColorInterval(leds,num_leds,12,4, 253, 215, 130);
	      setPixelColorInterval(leds,num_leds,12,5, 181, 198, 130);
	      setPixelColorInterval(leds,num_leds,12,6, 141, 189, 193);
	      setPixelColorInterval(leds,num_leds,12,7, 177, 217, 242);
	      setPixelColorInterval(leds,num_leds,12,8, 100, 165, 187);
	      setPixelColorInterval(leds,num_leds,12,9, 133, 105, 128);
	      setPixelColorInterval(leds,num_leds,12,10, 140, 166, 95);
	      setPixelColorInterval(leds,num_leds,12,11, 198, 44, 58);
	      setPixelColorInterval(leds,num_leds,12,0, 149, 69, 103);

	      FastLED.show();
	      delay(lng);

	    }//close of option 5
	  }//close level 2

	  if (soundLevel == 3)
	  {
	    //open if sound level 3
	    int level3Color = random(1, 5);

	    if (level3Color == 1) //run red
	    {
	      //open option 1

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 1 red

	    else if (level3Color == 2) //run green
	    {
	      //open option 2

	      setPixelColorInterval(leds,num_leds,12,0, 245, 116, 97);
	      setPixelColorInterval(leds,num_leds,12,1, 169, 221, 20);
	      setPixelColorInterval(leds,num_leds,12,2, 245, 116, 97);
	      setPixelColorInterval(leds,num_leds,12,3, 169, 221, 20);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 2green

	    else if (level3Color == 3) //run blue
	    {
	      //open option 3

	      setPixelColorInterval(leds,num_leds,12,0, 169, 221, 199);
	      setPixelColorInterval(leds,num_leds,12,1, 245, 116, 97);
	      setPixelColorInterval(leds,num_leds,12,2, 169, 221, 199);
	      setPixelColorInterval(leds,num_leds,12,3,  245, 116, 97);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 3 blue

	    else if (level3Color == 4) //run yellow
	    {
	      //open option 4

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 4 yellow

	    else if (level3Color == 5)
	    {
	      //open option 5
	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 105, 180);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 105, 180);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 105, 180);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 105, 180);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 105, 180);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,11, 255, 105, 180);
	      FastLED.show();
	      delay(sht);
	    }//close of option 5
	  }//close level 3


	  if (soundLevel == 4)
	  {
	    //open if sound level 4
	    int level4Color = random(1, 5);

	    if (level4Color == 1) //run red
	    {
	      //open option 1

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close red

	    else if (level4Color == 2) //run green
	    {
	      //open option 2

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close green

	    else if (level4Color == 3) //run blue
	    {
	      //open option 3

	      setPixelColorInterval(leds,num_leds,12,0, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close blue

	    else if (level4Color == 4) //run yellow
	    {
	      //open option 4

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close yellow

	    else if (level4Color == 5)
	    {
	      ////open option 5
	      setPixelColorInterval(leds,num_leds,12,0, 255, 01, 165);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 187, 218);
	      setPixelColorInterval(leds,num_leds,12,2, 228, 194, 191);
	      setPixelColorInterval(leds,num_leds,12,3, 153, 87, 205);
	      setPixelColorInterval(leds,num_leds,12,4, 176, 284, 218);
	      setPixelColorInterval(leds,num_leds,12,5, 67, 142, 200);
	      setPixelColorInterval(leds,num_leds,12,6, 107, 167, 214);
	      setPixelColorInterval(leds,num_leds,12,7, 168, 204, 232);
	      setPixelColorInterval(leds,num_leds,12,8, 59, 198, 182);
	      setPixelColorInterval(leds,num_leds,12,9, 100, 212, 199);
	      setPixelColorInterval(leds,num_leds,12,10, 164, 231, 223);
	      setPixelColorInterval(leds,num_leds,12,11, 176, 124, 218);
	      FastLED.show();
	      delay(lng);
	    }//close option 5

	  }//close if sound level 4

	  else if (soundLevel == 5)
	  {
	    //open if sound level 5


	    int level5Color = random(1, 6);

	    if (level5Color == 1) //run red
	    {
	      //open option 1

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 1 red

	    else if (level5Color == 2) //run green
	    {
	      //open option 2

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 2 green

	    else if (level5Color == 3) //run blue
	    {
	      //open option 3

	      setPixelColorInterval(leds,num_leds,12,0, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 3 blue

	    else if (level5Color == 4) //run yellow
	    {
	      //open option 4

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close yellow

	    else if (level5Color == 5)
	    {
	      //open option 5

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	setPixelColorInterval(leds,num_leds,12,6, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 255);
	      FastLED.show();
	      delay(lng);
	    }//close option 5

	    else if (level5Color == 6)
	    {
	      //open option 6

	      colorWipe(leds,num_leds,CRGB(255, 0, 255), 5); // magenta
	      colorWipe(leds,num_leds,CRGB(0, 255, 0), 5); // green
	      FastLED.show();
	    }//close option 6
	  }//close if sound level 5


	  else if (soundLevel == 6)
	  {
	    //open if soundlevel 6

	    int level6Color = random(1, 6);

	    if (level6Color == 1) //run red
	    {
	      //open option 1

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 1red

	    else if (level6Color == 2) //run green
	    {
	      //open option 2

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 2 green

	    else if (level6Color == 3) //run blue
	    {
	      //open option 3

	      setPixelColorInterval(leds,num_leds,12,0, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 3 blue

	    else if (level6Color == 4) //run yellow
	    {
	      //open option 4

	      setPixelColorInterval(leds,num_leds,12,0, 148, 0, 211);
	      setPixelColorInterval(leds,num_leds,12,1, 75, 0, 130);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 127, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(sht);
	    }//close yellow

	    else if (level6Color == 5)
	    {
	      //open option 5
	      colorWipe(leds,num_leds,CRGB(0, 0, 255), 5); // Blue
	      colorWipe(leds,num_leds,CRGB(255, 255, 0), 5); // yellow
	      FastLED.show();
	    }//close option 5

	    else if (level6Color == 6)
	    {
	      //open option6

	      theaterChase(leds,num_leds,CRGB(200, 0, 0), 5); // Red
	      FastLED.show();
	      delay(lng);
	    }//close option 6
	  }//close if sound level 6

	  else if (soundLevel == 7)
	  {
	    //open if sound level 7
	    int level7Color = random(1, 7);

	    if (level7Color == 1) //run red
	    {
	      //open option 1

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 1 red

	    else if (level7Color == 2) //run green
	    {
	      //open option 2

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 2 green

	    else if (level7Color == 3) //run blue
	    {
	      //open option 3

	      setPixelColorInterval(leds,num_leds,12,0, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 3 blue

	    else if (level7Color == 4) //run yellow
	    {
	      //open option 4

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 4 yellow

	    else if (level7Color == 5)
	    {
	      //open option 5
	      colorWipe(leds,num_leds,CRGB(255, 20, 147), 5); // pink
	      colorWipe(leds,num_leds,CRGB(0, 206, 209), 5); // turquoise
	      FastLED.show();
	      delay(lng);
	    }//close option 5

	    else if (level7Color == 6)
	    {
	      //open option 6

	      theaterChase(leds,num_leds,CRGB(255, 20, 100), 5); // Red
	      FastLED.show();
	      delay(sht);
	    }//close option 6

	    else if (level7Color == 7)
	    {
	      //open option 7
	      setPixelColorInterval(leds,num_leds,12,0, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,3, 50, 0, 150);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,7, 50, 0, 150);
	setPixelColorInterval(leds,num_leds,12,0, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,11, 50, 0, 150);

	      FastLED.show();
	      delay(sht);
	    }//close option 7
	  }//close if sound level 7

	  else if (soundLevel == 8)
	  {
	    //open if sound level 8

	    int level8Color = random(1, 8);

	    if (level8Color == 1) //run red
	    {
	      //open option 1
	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 1 red

	    else if (level8Color == 2) //run green/blue
	    {
	      //open option 2

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 2 green/blue

	    else if (level8Color == 3) //run turquoise / blue
	    {
	      //open option 3

	      setPixelColorInterval(leds,num_leds,12,0, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 3 blue

	    else if (level8Color == 4) //run yellow
	    {
	      //open option 4

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 4 yellow

	    else if (level8Color == 5)
	    {
	      //open option 5
	      colorWipe(leds,num_leds,CRGB(255, 20, 147), 2); // pink
	      colorWipe(leds,num_leds,CRGB(0, 206, 209), 2); // turquoise
	      FastLED.show();
	    }//close option 5

	    else if (level8Color == 6)
	    {
	      //open option 6

	      theaterChase(leds,num_leds,CRGB(0, 206, 209), 5); // Red
	      FastLED.show();
	      delay(sht);
	    }//close option 6

	    else if (level8Color == 7)
	    {
	      //open option 7
	      setPixelColorInterval(leds,num_leds,12,0, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,3, 50, 0, 150);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,7, 50, 0, 150);
	setPixelColorInterval(leds,num_leds,12,0, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,11, 50, 0, 150);

	      FastLED.show();
	      delay(lng);

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);


	    }//close option 7

	  }//close if sound level 8
*/
	  else if (soundLevel == 9)
	  {
	    //open if sound level 9

	    int level9Color = random(1, 8);

	    if (level9Color == 1) //run red
	    {
	      //open option 1

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 1 red

	    else if (level9Color == 2) //run green
	    {
	      //open option 2

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 2 green

	    else if (level9Color == 3) //run blue
	    {
	      //open option 3
	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 3blue

	    else if (level9Color == 4) //run yellow
	    {
	      //open option 4

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 4 yellow

	    else if (level9Color == 5)
	    {
	      //open option 5
	      colorWipe(leds,num_leds,CRGB(255, 255, 255), 6); // white
	      colorWipe(leds,num_leds,CRGB(0, 206, 209), 2); // turquoise
	      FastLED.show();
	    }//close option 5

	    else if (level9Color == 6)
	    {
	      //open option 6

	      theaterChase(leds,num_leds,CRGB(50, 190, 209), 5); // turquise
	      FastLED.show();
	      delay(lng);
	    }//close option 6

	    else if (level9Color == 7)
	    {
	      //open option 7
	      setPixelColorInterval(leds,num_leds,12,0, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,3, 50, 0, 150);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,7, 50, 0, 150);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,11, 50, 0, 150);

	      FastLED.show();
	      delay(lng);

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);

	      setPixelColorInterval(leds,num_leds,12,0, 255, 50, 50);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 50, 50);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 50, 50);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 50, 50);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 50, 50);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 50, 50);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 255);
	      FastLED.show();

	      delay(lng);


	    }//close option 7

	    else if (level9Color == 8)
	    {
	      //open option 8
	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);

	      FastLED.show();
	      delay (lng);

	      setPixelColorInterval(leds,num_leds,12,0, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 255, 255, 255);

	      FastLED.show();
	      delay(lng);


	    }//close option 9

	  }//close if sound level 9

	  else if (soundLevel == 10)

	  {
	    //open if sound Level 10

	    int level10Color = random(1, 8);

	    if (level10Color == 1) //run red
	    {
	      //open option 1

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 1 red

	    else if (level10Color == 2) //run green
	    {
	      //open option 2

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 2 green

	    else if (level10Color == 3) //run blue
	    {
	      //open option 3

	      setPixelColorInterval(leds,num_leds,12,0, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 3 blue

	    else if (level10Color == 4) //run yellow
	    {
	      //open option 4

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 4 yellow

	    else if (level10Color == 5)
	    {
	      //open option 5

	      colorWipe(leds,num_leds,CRGB(200, 40, 147), 5); // pink
	      colorWipe(leds,num_leds,CRGB(0, 206, 209), 2); // turquoise
	      FastLED.show();
	      delay(sht);
	    }//close option 5

	    else if (level10Color == 6)
	    {
	      //open option 6
	      theaterChase(leds,num_leds,CRGB(0, 206, 209), 5);
	      FastLED.show();
	      delay(sht);
	    }//close option 6

	    else if (level10Color == 7)
	    {
	      //open option 7
	      setPixelColorInterval(leds,num_leds,12,0, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,3, 50, 0, 150);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,7, 50, 0, 150);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,11, 50, 0, 150);

	      FastLED.show();
	      delay(lng);

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,11, 255, 255, 255);
	      FastLED.show();
	      delay(sht);

	    }//close option 7

	  }//close if sound level 10


	  else if (soundLevel >= 11)

	  {
	    //open if sound Level 11

	    int level11Color = random(1, 8);

	    if (level11Color == 1) //run red
	    {
	      //open option 1

	      setPixelColorInterval(leds,num_leds,12,0, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 255, 0, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 1 red

	    else if (level11Color == 2) //run green
	    {
	      //open option 2

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 255);
	      FastLED.show();
	      delay(lng);
	    }//close option 2  green

	    else if (level11Color == 3) //run blue
	    {
	      //open option 3

	      setPixelColorInterval(leds,num_leds,12,0, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 0, 255);
	      setPixelColorInterval(leds,num_leds,12,10, 0, 206, 255);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 255);
	      FastLED.show();
	      delay(lng);
	    }//close option 3 blue

	    else if (level11Color == 4) //run yellow
	    {
	      //open option 4

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 255, 255, 0);
	      FastLED.show();
	      delay(lng);
	    }//close option 4 yellow

	    else if (level11Color == 5)
	    {
	      //open option 5

	      colorWipe(leds,num_leds,CRGB(0, 40, 255), 5); // pink
	      colorWipe(leds,num_leds,CRGB(0, 209, 206), 2); // turquoise
	      FastLED.show();
	      delay(sht);
	    }//close option 5

	    else if (level11Color == 6) //open option 6
	    {
	      //open option 6
	      theaterChase(leds,num_leds,CRGB(0, 206, 109), 5);
	      FastLED.show();
	      delay(sht);
	    }//close option 6

	    else if (level11Color == 7)//open option 7
	    {
	      //open option 7
	      setPixelColorInterval(leds,num_leds,12,0, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,3, 50, 0, 150);
	      setPixelColorInterval(leds,num_leds,12,4, 0, 70, 70);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,7, 50, 0, 150);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,9, 0, 100, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 0, 70);
	      setPixelColorInterval(leds,num_leds,12,11, 50, 0, 150);

	      FastLED.show();
	      delay(lng);

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);

	      setPixelColorInterval(leds,num_leds,12,0, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,5, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,6, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,11, 255, 255, 255);
	      FastLED.show();
	      delay(lng);

	      setPixelColorInterval(leds,num_leds,12,0, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,1, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,2, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,3, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,4, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,5, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,6, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,7, 0, 255, 255);
	      setPixelColorInterval(leds,num_leds,12,8, 0, 0, 0);
	      setPixelColorInterval(leds,num_leds,12,9, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,10, 255, 255, 0);
	      setPixelColorInterval(leds,num_leds,12,11, 0, 0, 0);
	      FastLED.show();
	      delay(lng);

	    }//close option 7

	  }//close if sound level 11


}



void setPixelColorInterval(CRGB* leds,uint16_t num_leds,uint16_t interval,uint16_t pixel, uint8_t r, uint8_t g, uint8_t b){
	for(uint16_t pix = pixel; pix<num_leds;pix+=interval){
		leds[pix].r = r;
		leds[pix].g = g;
		leds[pix].b = b;
	}
}

void setPixelColorInterval(CRGB* leds,uint16_t num_leds,uint16_t interval,uint16_t pixel, uint32_t color){
	for(uint16_t pix = pixel; pix<num_leds;pix+=interval){
		leds[pix].r = color;
	}
}

void colorWipe(CRGB* leds, uint16_t num_leds,uint32_t c, uint8_t wait){
	/*
	for (uint16_t i=0; i< num_leds; i++){
		leds[i]=c;
		FastLED.show();
		delay(wait);
	}*/
	for (int j=0; j<3; j++){
			for(int q=0;q<3;q++){
				for (int i=0;i<num_leds-3;i=i+3){
					leds[i+q]=c;
				}
				FastLED.show();
				delay(wait);
				for (int i=0;i<num_leds-3;i=i+3){
					leds[i+q]=0;
				}

			}

		}
}

void theaterChase(CRGB* leds, uint16_t num_leds,uint32_t c, uint16_t wait){

	for (int j=0; j<3; j++){
		for(int q=0;q<3;q++){
			for (int i=0;i<num_leds-3;i=i+3){
				leds[i+q]=c;
			}
			FastLED.show();
			delay(wait);
			for (int i=0;i<num_leds-3;i=i+3){
				leds[i+q]=0;
			}

		}

	}
}
