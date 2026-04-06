#pragma once

class DateTime 
{
private:
	int year;
	int month;
	int day;

	bool isLeapYear(int y) const;
	int daysInMonth(int y, int m) const;
	long long toDays() const;

public:
	DateTime();
	DateTime(int y, int m, int d);

	void input();
	void basicFormat() const;
	void textFormat() const;
	void shortFormat() const;

	bool isValid() const;

	int operator - (const DateTime& other) const;

	int dayOfWeek() const;
};