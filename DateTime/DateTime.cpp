#include "DateTime.h"
#include <iostream>

using namespace std;

DateTime::DateTime() : year(2003), month(1), day(24) {}

DateTime::DateTime(int y, int m, int d) : year(y), month(m), day(d) {}

bool DateTime::isLeapYear(int y) const 
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int DateTime::daysInMonth(int y, int m) const 
{
	static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (m == 2 && isLeapYear(y)) 
        return 29;
	return days[m - 1];
}

long long DateTime::toDays() const
{
    long long totalDays = 0;

    for (int y = 1; y < year; y++) 
    {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < month; m++) 
    {
        totalDays += daysInMonth(year, m);
    }

    totalDays += day;

    return totalDays;
}

bool DateTime::isValid() const {
    if (year < 1 || year > 9999) return false;

    if (month < 1 || month > 12) return false;

    if (day < 1 || day > daysInMonth(year, month)) return false;

    return true;
}

void DateTime::input()
{
	char point1, point2;
	cout << "Введите дату в формате дд.мм.гггг: ";
	cin >> day >> point1 >> month >> point2 >> year;

    if (!isValid()) 
    {
        cout << "\nОшибка: введена некорректная дата!" << endl;
        year = 2003;
        month = 1;
        day = 24;
    }
}

void printWithLeadingZero(int num) 
{
    if (num < 10) 
        cout << "0";
    
    cout << num;
}

void DateTime::basicFormat() const 
{
    cout << day << ".";
    printWithLeadingZero(month);
    cout << "." << year;
}

void DateTime::textFormat() const 
{
    static const char* months[] = {
        "января", "февраля", "марта", "апреля", "мая", "июня",
        "июля", "августа", "сентября", "октября", "ноября", "декабря"
    };

    cout << day << " " << months[month - 1] << " " << year;
}

void DateTime::shortFormat() const 
{
    printWithLeadingZero(day);
    cout << ".";
    printWithLeadingZero(month);
    cout << ".";
    printWithLeadingZero(year % 100);
}

int DateTime::operator - (const DateTime& other) const 
{
    long long days1 = toDays();
    long long days2 = other.toDays();
    if (days1 > days2) 
        return days1 - days2;
    else
        return days2 - days1;
}

int DateTime::dayOfWeek() const 
{
    int d = day;
    int m = month;
    int y = year;

    if (m < 3) {
        m += 12;
        y--;
    }

    int K = y % 100;
    int J = y / 100;

    int h = (d + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    int dayOfWeek = (h + 5) % 7;

    return dayOfWeek;
}