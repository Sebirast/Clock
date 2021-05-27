#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include <Arduino.h>
#include <assert.h>

namespace display
{
struct SegmentPins
{
	int dotPin;
	int topPin;
	int topRightPin;
	int topLeftPin;
	int middlePin;
	int bottomRightPin;
	int bottomLeftPin;
	int bottomPin;
	int powerPin;

	void forEach(void (*func)(int));
};

struct SegmentPinWrite
{
	bool dotPin;
	bool topPin;
	bool topRightPin;
	bool topLeftPin;
	bool middlePin;
	bool bottomRightPin;
	bool bottomLeftPin;
	bool bottomPin;
};

// index to the array is the number that is returned in form of a SegmentPinWrite
const SegmentPinWrite numbers[] = {
	SegmentPinWrite{false, true, true, true, false, true, true, true},	   // 0
	SegmentPinWrite{false, false, true, false, false, true, false, false}, // 1
	SegmentPinWrite{false, true, true, false, true, false, true, true},	   // 2
	SegmentPinWrite{false, true, true, false, true, true, false, true},	   // 3
	SegmentPinWrite{false, false, true, true, true, true, false, false},   // 4
	SegmentPinWrite{false, true, false, true, true, true, false, true},	   // 5
	SegmentPinWrite{false, true, false, true, true, true, true, true},	   // 6
	SegmentPinWrite{false, true, true, false, false, true, false, false},  // 7
	SegmentPinWrite{false, true, true, true, true, true, true, true},	   // 8
	SegmentPinWrite{false, true, true, true, true, true, false, true},	   // 9
};

class SevenSegment
{
private:
	SegmentPins pins;

	void set(SegmentPinWrite number);

public:
	SevenSegment(const int pointPin, const int topPin, const int topRightPin, const int topLeftPin, const int middlePin, const int bottomRightPin, const int bottomLeftPin, const int bottomPin, const int powerPin);
	SevenSegment(SegmentPins segmentPins);

	void clearDisplay();

	void set(int number);
	void set(int number, bool point);
	void set(bool point);
};
} // namespace display

#endif