#pragma once

namespace utils
{

// Base 4k resolution
const float baseWindowWidth = 3840.0f;
const float baseWindowHeight = 2160.0f;

const float baseAspectRatio = baseWindowWidth / baseWindowHeight;

extern int viewportX;
extern int viewportY;

extern int viewportWidth;
extern int viewportHeight;

extern float windowWidth;
extern float windowHeight;

extern float windowAspect;

extern float widthScale;
extern float heightScale;

} // namespace utils
