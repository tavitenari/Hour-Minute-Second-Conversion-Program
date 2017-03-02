/*
Ioane "Tavi" Tenari
Prof. Dimspey, CSS 342
10/12/16
Program 1
*/
#include "stdafx.h"
#include "TimeSpan.h"

int main()
{
	TimeSpan dur1 = TimeSpan(1.5, 4, -10);
	TimeSpan dur2 = TimeSpan(1, 120, 30);
	TimeSpan dur3 = TimeSpan(-10, -10, -10);
	TimeSpan dur4 = TimeSpan(-6, -7, -8);
	TimeSpan dur5;
	TimeSpan dur6 = TimeSpan(1);
	TimeSpan dur7 = TimeSpan(2, 1);
	
	cout << dur1 << endl;
	cout << "dur1's Hours: " << dur1.getHours() << endl;
	cout << "dur1's Minutes: " << dur1.getMinutes() << endl;
	cout << "dur1's Seconds: " << dur1.getSeconds() << endl;
	dur1.setTime(4, 3, 2);
	cout << "dur1's new time has been set to: " << dur1 << endl;
	TimeSpan sum = dur1 + dur3;
	TimeSpan sum2 = dur1 - dur3;
	cout << "dur1 + dur3 produces this: " << sum << endl;
	cout << "dur1 - dur3 produces this: " << sum2 << endl;
	sum += sum2;
	cout << "sum += sum2 is this: " << sum << endl;
	sum -= sum2;
	cout << "sum -= sum2 is this: " << sum << endl;
	if (sum == dur4)
	{
		cout << "check" << endl;
	}
	if (sum != dur3)
	{
		cout << "check" << endl;
	}
	sum = -sum;
	cout << sum << endl;
	cout << dur5 << endl;
	cout << dur6 << endl;
	cout << dur7 << endl;
	cout << endl;

	cout << "Input Hours, Minutes, Seconds: " << endl;
	cin >> dur5;
	cout << "Time input is as follows: " << dur5 << endl;
	system("pause");
	return 0;
}

