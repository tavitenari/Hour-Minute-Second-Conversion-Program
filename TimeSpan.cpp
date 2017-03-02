/*
Ioane "Tavi" Tenari
Prof. Dimspey, CSS 342
10/12/16
Program 1
*/
#include "stdafx.h"
#include "TimeSpan.h"

TimeSpan::TimeSpan()
{
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

TimeSpan::TimeSpan(double seconds)
{
	FormatTime(0, 0, seconds);
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
	FormatTime(0, minutes, seconds);
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	FormatTime(hours, minutes, seconds);
}

TimeSpan::~TimeSpan()
{
}

int TimeSpan::getHours() const
{
	return hours;
}

int TimeSpan::getMinutes() const
{
	return minutes;
}

int TimeSpan::getSeconds() const
{
	return seconds;
}

bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
	FormatTime(hours, minutes, seconds);
	return true;
}

TimeSpan TimeSpan::operator+(const TimeSpan &tim) const
{
	TimeSpan tempSpan = *this;
	tempSpan += tim;
	return tempSpan;

}

TimeSpan& TimeSpan::operator+=(const TimeSpan &tim)
{
	hours = hours + tim.hours;
	minutes = minutes + tim.minutes;
	seconds = seconds + tim.seconds;
	FormatTime(hours, minutes, seconds);
	return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan &tim) const
{
	TimeSpan tempSpan = *this;
	tempSpan -= tim;
	return tempSpan;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan &tim)
{
	hours = hours - tim.hours;
	minutes = minutes - tim.minutes;
	seconds = seconds - tim.seconds;
	FormatTime(hours, minutes, seconds);
	return *this;
}

TimeSpan TimeSpan::operator-() const
{
	TimeSpan tempSpan;
	tempSpan.hours = -hours;
	tempSpan.minutes = -minutes;
	tempSpan.seconds = -seconds;
	return tempSpan;
}

bool TimeSpan::operator==(const TimeSpan &tim) const
{
	return ((hours == tim.hours) && (minutes == tim.minutes) && (seconds == tim.seconds));
}

bool TimeSpan::operator!=(const TimeSpan &tim) const 
{
	return ((hours != tim.hours) || (minutes != tim.minutes) || (seconds != tim.seconds));
}

//Formats hours, minutes, seconds in the range of -60 to 60
void TimeSpan::FormatTime(const double &hours, const double &minutes, const double &seconds)
{
	double tempSeconds = round(seconds + (3600 * hours + 60 * minutes));
	double tempMinutes = 0;
	double tempHours = 0;

	if (abs(tempSeconds) >= 60)
	{
		tempMinutes += int(tempSeconds / 60);
		tempSeconds = int(tempSeconds) % 60;
	}
	if (abs(tempMinutes) >= 60)
	{
		tempHours += int(tempMinutes / 60);
		tempMinutes = int(tempMinutes) % 60;
	}
	this->hours = tempHours;
	this->minutes = tempMinutes;
	this->seconds = tempSeconds;
}

ostream& operator<<(ostream &outStream, const TimeSpan &tim)
{
	outStream << "Hours: " << tim.hours << " Minutes: " << tim.minutes << " Seconds: " << tim.seconds;
	return outStream;
}

istream& operator>>(istream &inStream, TimeSpan &tim)
{
	inStream >> tim.hours >> tim.minutes >> tim.seconds;
	tim.FormatTime(tim.hours, tim.minutes, tim.seconds);
	return inStream;
}
