/*
FILE: drawing.cpp
AUTHOR: Alan Wolfe (alan.wolfe@gmail.com)
DATE: 2/8/2019

Description:
Some helper functions for drawing 2d images
*/

#include "drawing.h"
#include "image.h"
#include <algorithm>

float SmoothStep(float value, float min, float max)
{
    float x = (value - min) / (max - min);
    x = std::min(x, 1.0f);
    x = std::max(x, 0.0f);

    return 3.0f * x * x - 2.0f * x * x * x;
}

template <typename T>
T Lerp(T A, T B, float t)
{
    return T(float(A) * (1.0f - t) + float(B) * t);
}

void DrawLine(Image& image, int x1, int y1, int x2, int y2, const PixelRGBU8& color)
{
    // pad the AABB of pixels we scan, to account for anti aliasing
    int startX = std::max(std::min(x1, x2) - 4, 0);
    int startY = std::max(std::min(y1, y2) - 4, 0);
    int endX = std::min(std::max(x1, x2) + 4, image.m_width - 1);
    int endY = std::min(std::max(y1, y2) + 4, image.m_height - 1);

    // if (x1,y1) is A and (x2,y2) is B, get a normalized vector from A to B called AB
    float ABX = float(x2 - x1);
    float ABY = float(y2 - y1);
    float ABLen = std::sqrtf(ABX*ABX + ABY * ABY);
    ABX /= ABLen;
    ABY /= ABLen;

    // scan the AABB of our line segment, drawing pixels for the line, as is appropriate
    for (int iy = startY; iy <= endY; ++iy)
    {
        PixelRGBU8* pixel = &image.m_pixels[(iy * image.m_width + startX)];
        for (int ix = startX; ix <= endX; ++ix)
        {
            // project this current pixel onto the line segment to get the closest point on the line segment to the point
            float ACX = float(ix - x1);
            float ACY = float(iy - y1);
            float lineSegmentT = ACX * ABX + ACY * ABY;
            lineSegmentT = std::min(lineSegmentT, ABLen);
            lineSegmentT = std::max(lineSegmentT, 0.0f);
            float closestX = float(x1) + lineSegmentT * ABX;
            float closestY = float(y1) + lineSegmentT * ABY;

            // calculate the distance from this pixel to the closest point on the line segment
            float distanceX = float(ix) - closestX;
            float distanceY = float(iy) - closestY;
            float distance = std::sqrtf(distanceX*distanceX + distanceY * distanceY);

            // use the distance to figure out how transparent the pixel should be, and apply the color to the pixel
            float alpha = SmoothStep(distance, 2.0f, 0.0f);

            if (alpha > 0.0f)
            {
                pixel->r = Lerp(pixel->r, color.r, alpha);
                pixel->g = Lerp(pixel->g, color.g, alpha);
                pixel->b = Lerp(pixel->b, color.b, alpha);
            }

            pixel++;
        }
    }
}