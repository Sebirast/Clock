#include "Clock.h"

bool Clock::increaseMinutes(void *voidClockPtr)
{
    Clock &clock = *(Clock *)voidClockPtr;
    if (clock.minutes == 59)
    {
        clock.minutes = 0;
        clock.hours = (clock.hours + 1) % 24;
    }
    else
        clock.minutes++;
    return true;
}

Clock::Clock(SegmentPins pins, int powerPinHourHigh, int powerPinHourLow, int powerPinMinuteHigh, int powerPinMinuteLow)
{
    pins.powerPin = powerPinHourHigh;
    hourSegmentHigh = SevenSegment{pins};

    pins.powerPin = powerPinHourLow;
    hourSegmentLow = SevenSegment{pins};

    pins.powerPin = powerPinMinuteHigh;
    minuteSegmentHigh = SevenSegment{pins};

    pins.powerPin = powerPinMinuteLow;
    minuteSegmentLow = SevenSegment{pins};

    timer = timer_create_default();
    timer.every(60000, increaseMinutes, this);
}

void Clock::setTime(int hours, int minutes)
{
    this->hours = hours;
    this->minutes = minutes;
}

void Clock::update()
{
    hourSegmentHigh.activate();
    hourSegmentHigh.set((hours - (hours % 10)) / 10);
    delay(setDelay);
    hourSegmentHigh.deactivate();
    hourSegmentLow.activate();
    hourSegmentLow.set(hours % 10);
    delay(setDelay);
    hourSegmentLow.deactivate();

    minuteSegmentHigh.activate();
    minuteSegmentHigh.set((minutes - (minutes % 10)) / 10);
    delay(setDelay);
    minuteSegmentHigh.deactivate();
    minuteSegmentLow.activate();
    minuteSegmentLow.set(minutes % 10);
    delay(setDelay);
    minuteSegmentLow.deactivate();

    timer.tick();
}