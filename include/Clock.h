#ifndef CLOCK_H
#define CLOCK_H

#include "SevenSegment.h"
#include <arduino-timer.h>

using namespace display;

class Clock
{
private:    
    int hours = 0;
    int minutes = 0;

    SevenSegment hourSegmentLow;
    SevenSegment hourSegmentHigh;
    SevenSegment minuteSegmentLow;
    SevenSegment minuteSegmentHigh;

    Timer<> timer;

    static bool increaseMinutes(void* clock);

    const int setDelay = 4;

public:
    Clock(display::SegmentPins pins, int powerPinHourHigh, int powerPinHourLow, int powerPinMinuteHigh, int powerPinMinuteLow);
    void update();
    void setTime(int hours, int minutes);
};

#endif