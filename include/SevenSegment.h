#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include <Arduino.h>

namespace display
{
    class SevenSegment
    {
    private:
        int dotPin;
        int topPin;
        int topRightPin;
        int topLeftPin;
        int middlePin;
        int bottomRightPin;
        int bottomLeftPin;
        int bottomPin;
        int segmentPins [];  

    public:
        SevenSegment(const int pointPin, const int topPin, const int topRightPin, const int topLeftPin, const int middlePin, const int bottomRightPin, const int bottomLeftPin, const int bottomPin); 

        void clearDisplay();

        void set(int number);
    };
}

#endif