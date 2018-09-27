/*
 * windowutils.cpp
 *
 *  Created on: 14 dic. 2017
 *      Author: extplgarcia
 */

#include "windowutils.h"

namespace utils
{

float windowWidth = 0.0f;
float windowHeight = 0.0f;

float windowAspect = 0.0f;

float widthScale = baseWindowWidth / windowWidth;
float heightScale = baseWindowHeight / windowHeight;

int viewportX = 0;
int viewportY = 0;

int viewportWidth = 0;
int viewportHeight = 0;

} // namespace utils
