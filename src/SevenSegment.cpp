#include "SevenSegment.h"

using namespace display;
SevenSegment::SevenSegment(const int dotPin, const int topPin, const int topRightPin, const int topLeftPin, const int middlePin, const int bottomRightPin, const int bottomLeftPin, const int bottomPin, int powerPin) : pins({dotPin, topPin, topRightPin, topLeftPin, middlePin, bottomRightPin, bottomLeftPin, bottomPin})
{
    pins.forEach([](int pin)
                 { pinMode(pin, OUTPUT); });
}

SevenSegment::SevenSegment(SegmentPins pins) : pins(pins)
{
    pins.forEach([](int pin)
                 { pinMode(pin, OUTPUT); });
}

void SegmentPins::forEach(void (*func)(int))
{
    func(dotPin);
    func(topPin);
    func(topRightPin);
    func(topLeftPin);
    func(middlePin);
    func(bottomRightPin);
    func(bottomLeftPin);
    func(bottomPin);
}

void SevenSegment::set(int number, bool point)
{
    assert(("Index out of bounds, number must be greater equal 0 and smaller than 10", number < 10 && number >= 0));
    auto segmentNumber = numbers[number];
    segmentNumber.dotPin = point;
    set(segmentNumber);
}

void SevenSegment::set(bool point)
{
    digitalWrite(pins.dotPin, point);
    set(SegmentPinWrite{true, false, false, false, false, false, false, false});
}

void SevenSegment::set(int number)
{
    set(number, false);
}

void SevenSegment::set(SegmentPinWrite number)
{
    digitalWrite(pins.dotPin, number.dotPin);
    digitalWrite(pins.topPin, number.topPin);
    digitalWrite(pins.topRightPin, number.topRightPin);
    digitalWrite(pins.topLeftPin, number.topLeftPin);
    digitalWrite(pins.middlePin, number.middlePin);
    digitalWrite(pins.bottomRightPin, number.bottomRightPin);
    digitalWrite(pins.bottomLeftPin, number.bottomLeftPin);
    digitalWrite(pins.bottomPin, number.bottomPin);
}