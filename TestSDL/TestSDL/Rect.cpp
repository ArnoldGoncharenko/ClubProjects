#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Rect.h"

using namespace std;

newRect::newRect()
{
	x = 1;
	y = 1;
	h = 1;
	w = 1;
}

SDL_Rect& newRect::createNewRect(short xVal, short yVal, short hVal, short wVal)
{
	SDL_Rect tempRect;
	tempRect.x = xVal;
	tempRect.y = yVal;
	tempRect.h = hVal;
	tempRect.w = wVal;

	return tempRect;
}