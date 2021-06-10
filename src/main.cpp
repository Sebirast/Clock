#include <Arduino.h>
#include "Clock.h"
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
	-1};

Clock clock{pins, A0, A1, A2, A3};

unsigned long startTime;
void setup()
{
	clock.setTime(8, 34);
	startTime = millis();
	Serial.begin(9600);
}

long counter = 0;
void loop()
{
	clock.update();
	counter++;
	if (millis() - startTime > 2000)
	{
		Serial.println(counter / (float)(millis() - startTime) * 1000);
		startTime = millis();
		counter = 0;
	}
}