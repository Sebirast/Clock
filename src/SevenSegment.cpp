#include <../include/SevenSegment.h>

using namespace display;

SevenSegment::SevenSegment(int dotPin, const int topPin, const int topRightPin, const int topLeftPin, const int middlePin, const int bottomRightPin, const int bottomLeftPin, const int bottomPin) 
{
    this->dotPin = dotPin;
    this->topPin = topPin;
    this->topRightPin = topRightPin;
    this->topLeftPin = topLeftPin;
    this->middlePin = middlePin;
    this->bottomRightPin = bottomRightPin;
    this->bottomLeftPin = bottomLeftPin;
    this->bottomPin = bottomPin;
    
    this.segmentPins = {dotPin, topPin, topRightPin, topLeftPin, middlePin, bottomRightPin, bottomLeftPin, bottomPin};
}