/*
Ioane "Tavi" Tenari
Prof. Dimspey, CSS 342
10/12/16
Program 1
*/
#pragma once
#include <iostream>
using namespace std;

class TimeSpan
{
	
	friend ostream& operator<<(ostream &outStream, const TimeSpan &tim);
	friend istream& operator>>(istream &inStream, TimeSpan &tim);

public:

//Constructors - Destructor
	TimeSpan();
	TimeSpan(double seconds);
	TimeSpan(double minutes, double seconds);
	TimeSpan(double hours, double minutes, double seconds);
	~TimeSpan();

//Getters - Setters
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	bool setTime(int hours, int minutes, int seconds);

//Operator Overloads
	TimeSpan operator+(const TimeSpan &tim) const;
	TimeSpan& operator+=(const TimeSpan &tim);
	TimeSpan operator-(const TimeSpan &tim) const;
	TimeSpan& operator-=(const TimeSpan &tim);
	TimeSpan operator-() const;
	bool TimeSpan::operator==(const TimeSpan &tim) const;
	bool TimeSpan::operator!=(const TimeSpan &tim) const;

private:
	//Formats hours, minutes, seconds in the range of -60 to 60
	void FormatTime(const double &hours, const double &minutes, const double &seconds);
	
	int hours;
	int minutes;
	int seconds;
};