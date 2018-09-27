/*
 * mathutils.cpp
 *
 *  Created on: 13 dic. 2017
 *      Author: extplgarcia
 */

#include "mathutils.h"

namespace utils
{

float mapToRange(float value, float inputStart, float inputEnd, float outputStart, float outputEnd)
{
	return outputStart + ((outputEnd - outputStart) / (inputEnd - inputStart)) * (value - inputStart);
}

glm::vec2 toUvCoordinates(glm::vec2 value, glm::vec2 rectanglePosition, glm::vec2 size)
{
	value.x = utils::mapToRange(value.x, rectanglePosition.x, rectanglePosition.x + size.x, 0, 1);
	value.y = utils::mapToRange(value.y, rectanglePosition.y, rectanglePosition.y + size.y, 0, 1);

	return value;
}

}
