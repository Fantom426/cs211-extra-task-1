#include <iostream>
#include <cassert>
#include <cmath>

double seconds_difference(double time_1, double time_2);
double hours_difference(double time_1, double time_2);
double to_float_hours(int hours, int minutes, int seconds);
double to_24_hour_clock(double hours);
int get_hours(int seconds);
int get_minutes(int seconds);
int get_seconds(int seconds);
double time_to_utc(int utc_offset, double time);
double time_from_utc(int utc_offset, double time);

int main() {
	assert((seconds_difference(1800.0, 3600.0) - 1800.0 < DBL_EPSILON) && "test-1");
	assert((seconds_difference(3600.0, 1800.0) -( -1800.0) < DBL_EPSILON) && "test-2");
	assert((seconds_difference(1800.0, 2160.0) - 360.0 < DBL_EPSILON) && "test-3");
	assert((seconds_difference(1800.0, 1800.0) < DBL_EPSILON) && "test-4");

	assert((hours_difference(1800.0, 3600.0) - 0.5 < DBL_EPSILON) && "test-5");
	assert((hours_difference(3600.0, 1800.0) -(-0.5) < DBL_EPSILON) && "test-6");
	assert((hours_difference(1800.0, 2160.0) - 0.1 < DBL_EPSILON) && "test-7");
	assert((hours_difference(1800.0, 1800.0) < DBL_EPSILON) && "test-8");

	assert((to_float_hours(0, 15, 0) - 0.25 < DBL_EPSILON) && "test-9");
	assert((to_float_hours(2, 45, 9) - 2.7525 < DBL_EPSILON) && "test-10");
	assert((to_float_hours(1, 0, 36) - 1.01 < DBL_EPSILON) && "test-11");

	assert((to_24_hour_clock(24) < DBL_EPSILON) && "test-12");
	assert((to_24_hour_clock(48) < DBL_EPSILON) && "test-13");
	assert((to_24_hour_clock(25) - 1 < DBL_EPSILON) && "test-14");
	assert((to_24_hour_clock(4) - 4 < DBL_EPSILON) && "test-15");
	assert((to_24_hour_clock(28.5) - 4.5 < DBL_EPSILON) && "test-16");

	assert((get_hours(3800) == 1) && "test-17");
	assert((get_minutes(3800) == 3) && "test-18");
	assert((get_seconds(3800) == 20) && "test-19");

	assert((time_to_utc(0, 12.0) - 12.0 < DBL_EPSILON) && "test-20");
	assert((time_to_utc(1, 12.0) - 11.0 < DBL_EPSILON) && "test-21");
	assert((time_to_utc(-1, 12.0) - 13.0 < DBL_EPSILON) && "test-22");
	assert((time_to_utc(-11, 18.0) - 5.0 < DBL_EPSILON) && "test-23");
	assert((time_to_utc(-1, 0.0) - 1.0 < DBL_EPSILON) && "test-24");
	assert((time_to_utc(-1, 23.0) - 0.0 < DBL_EPSILON) && "test-25");

	assert((time_from_utc(0, 12.0) - 12.0 < DBL_EPSILON) && "test-26");
	assert((time_from_utc(1, 12.0) - 13.0 < DBL_EPSILON) && "test-27");
	assert((time_from_utc(-1, 12.0) - 11.0 < DBL_EPSILON) && "test-28");
	assert((time_from_utc(6, 6.0) - 12.0 < DBL_EPSILON) && "test-29");
	assert((time_from_utc(-7, 6.0) - 23.0 < DBL_EPSILON) && "test-30");
	assert((time_from_utc(-1, 0.0) - 23.0 < DBL_EPSILON) && "test-31");
	assert((time_from_utc(-1, 23.0) - 22.0 < DBL_EPSILON) && "test-32");
	assert((time_from_utc(1, 23.0) < DBL_EPSILON) && "test-33");
}


double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;

	/*
	Return the number of seconds later that a time in seconds
	time_2 is than a time in seconds time_1.

	>>> seconds_difference(1800.0, 3600.0)
	1800.0

	>>> seconds_difference(3600.0, 1800.0)
	-1800.0

	>>> seconds_difference(1800.0, 2160.0)
	360.0

	>>> seconds_difference(1800.0, 1800.0)
	0.0
	*/
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600.0;
	/*
	Return the number of hours later that a time in seconds
	time_2 is than a time in seconds time_1.

	>>> hours_difference(1800.0, 3600.0)
	0.5

	>>> hours_difference(3600.0, 1800.0)
	-0.5

	>>> hours_difference(1800.0, 2160.0)
	0.1

	>>> hours_difference(1800.0, 1800.0)
	0.0
	*/
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert((minutes >= 0) && (minutes < 60) && (seconds >= 0) && (seconds < 60));
	return hours + (minutes / 60.0) + (seconds / 3600.0);
	/*
	Return the total number of hours in the specified number
	of hours, minutes, and seconds.

	Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

	>>> to_float_hours(0, 15, 0)
	0.25

	>>> to_float_hours(2, 45, 9)
	2.7525

	>>> to_float_hours(1, 0, 36)
	1.01
	*/
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	int H = floor(hours);
	return (H % 24) + hours - floor(hours); 
	/*
	hours is a number of hours since midnight. Return the
	hour as seen on a 24-hour clock.

	Precondition: hours >= 0

	>>> to_24_hour_clock(24)
	0

	>>> to_24_hour_clock(48)
	0

	>>> to_24_hour_clock(25)
	1

	>>> to_24_hour_clock(4)
	4

	>>> to_24_hour_clock(28.5)
	4.5

	You may wish to inspect various function in <cmath> to work
	with integer and fractional part of a hours separately.

	*/
}

int get_hours(int seconds) {
	return seconds / 3600;
}

int get_minutes(int seconds) {
	return (seconds / 60) % 60;
}

int get_seconds(int seconds) {
	return (seconds % 3600) % 60;
}
/*
Implement three functions
* get_hours
* get_minutes
* get_seconds
They are used to determine the hours part, minutes part and seconds part
of a time in seconds. E.g.:

>>> get_hours(3800)
1

>>> get_minutes(3800)
3

>>> get_seconds(3800)
20

In other words, if 3800 seconds have elapsed since midnight,
it is currently 01:03:20 (hh:mm:ss).
*/

double time_to_utc(int utc_offset, double time)
{
	int H = time - utc_offset;
	return H % 24;
	/*
	Return time at UTC+0, where utc_offset is the number of hours away from
	UTC+0.
	You may be interested in:
	https://en.wikipedia.org/wiki/Coordinated_Universal_Time

	>>> time_to_utc(+0, 12.0)
	12.0

	>>> time_to_utc(+1, 12.0)
	11.0

	>>> time_to_utc(-1, 12.0)
	13.0

	>>> time_to_utc(-11, 18.0)
	5.0

	>>> time_to_utc(-1, 0.0)
	1.0

	>>> time_to_utc(-1, 23.0)
	0.0
	*/
}

double time_from_utc(int utc_offset, double time)
{
	int H = time + utc_offset;
	H = H % 24;
	while (H < 0)
		H += 24;
	return H;
	/*
	Return UTC time in time zone utc_offset.

	>>> time_from_utc(+0, 12.0)
	12.0

	>>> time_from_utc(+1, 12.0)
	13.0

	>>> time_from_utc(-1, 12.0)
	11.0

	>>> time_from_utc(+6, 6.0)
	12.0

	>>> time_from_utc(-7, 6.0)
	23.0

	>>> time_from_utc(-1, 0.0)
	23.0

	>>> time_from_utc(-1, 23.0)
	22.0

	>>> time_from_utc(+1, 23.0)
	0.0
	*/
}
