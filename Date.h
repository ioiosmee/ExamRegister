#pragma once
#include <iostream>

class Date
{
private:
	short day;
	short month;
	short year;
public:
	Date(); // ����������� �� ���������
	Date(short, short, short); // ����������� � �����������
	void show_date(); // ����� ����
	Date operator = (Date r); // ���������� ��������� =
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