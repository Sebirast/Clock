#include <Arduino.h>
#include "SevenSegment.h"

const display::SegmentPins pins{
	13,
		12,
			11,		
	10,
		9,
			8,
	7,
		6,
	5
};
display::SevenSegment minuteSegmentLow{pins};
display::SevenSegment minuteSegmentHigh{pins};
display::SevenSegment hourSegmentLow{pins};
display::SevenSegment hourSegmentHigh{pins};


void setup()
{
	hourSegmentHigh.activate();
}

void loop()
{
	hourSegmentHigh.set(7);
}