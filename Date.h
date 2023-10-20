#pragma once
#include <iostream>

class Date
{
private:
	short day;
	short month;
	short year;
public:
	Date(); // конструктор по умолчанию
	Date(short, short, short); // конструктор с аргументами
	void show_date(); // вывод даты
	Date operator = (Date r); // перегрузка оператора =
	short return_day();
	short return_month();
	short return_year();
};

Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(short d, short m, short y)
{
	day = d;
	month = m;
	year = y;
}

short Date::return_day()
{
	return day;
}
short Date::return_month()
{
	return month;
}
short Date::return_year()
{
	return year;
}

void Date::show_date()
{
	std::cout << day << '.' << month << '.' << year;
}

Date Date::operator=(Date r)
{
	this->day = r.day;
	this->month = r.month;
	this->year = r.year;
	return *this;
}