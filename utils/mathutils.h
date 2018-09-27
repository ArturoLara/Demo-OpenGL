/*
 * mathutils.h
 *
 *  Created on: 13 dic. 2017
 *      Author: extplgarcia
 */

#pragma once

#include <glm/vec2.hpp>

namespace utils
{

// Maps a value from a range to another range of values
float mapToRange(float value, float inputStart, float inputEnd, float outputStart, float outputEnd);

// Maps x and y coordinates from value to uv coordinates (from 0 to 1)
glm::vec2 toUvCoordinates(glm::vec2 mousePos, glm::vec2 position, glm::vec2 size);

}
