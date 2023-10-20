#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "Date.h"

using namespace std;

class Register
{
private:
	string snils;			// снилс пациента
	map<Date, vector<short>> date_cabinet; // key - дата посещения поликлиники : value - номера кабинетов, в которых побывал пациент за данное посещение поликлиники

public:
	Register();
	Register(string, map<Date, vector<short>>);
	void set_snils(string);							// ввести снилс
	void add_date_and_cabinets(Date, vector<short>);// добавить дату и кабинеты, которые посетил пациент за это число
	void show_register();							// вывод реестра на экран
	void save_to_file(string, Date, vector<short>); // сохранение в файл
	bool check_the_snils(string);					// проверка снилса на верность

};

Register::Register()
{
	snils = "";
	date_cabinet.clear();
}
Register::Register(string snils_, map<Date, vector<short>> date_cab_)
{
	while (check_the_snils(snils_) != true)
	{
		cout << "wrong snils!!! Try again" << endl;
		cin >> snils_;
	}
	this->snils = snils_;
	Date temp_date;
	vector<short> temp;
	for (auto s : date_cab_) //
	{
		temp_date = s.first;
		for (short cab : s.second)
		{
			temp.push_back(cab);
		}
		date_cabinet.insert({ s.first,temp });
	}
	save_to_file(snils_, temp_date, temp);
}

void Register::set_snils(string snils_)
{
	this->snils = snils_;
}

void Register::add_date_and_cabinets(Date date, vector<short> cab)
{
	date_cabinet.insert({ date,cab });
	save_to_file(snils, date, cab);
}

bool Register::check_the_snils(string snils_)
{
	int sum = 0, check_number = 0, i = 9;
	bool flag = false;
	for (char c : snils_)
	{
		if (c == ' ')
			flag = true;
		else if ('0' <= c <= '9' && flag == false) // числа до пробела
		{
			sum += (c - '0') * i;
			i--;
		}
		else if ('0' <= c <= '9' && flag == true) // контрольное число
		{
			check_number *= 10 + (c - '0');
		}
		else if (c == '-')
			continue;
	}

	if (sum == 100)
		sum = 0;
	if (sum % 101 == check_number)
		return true;
	else
		return false;

}

void Register::save_to_file(string snils_, Date date_, vector<short> cab_)
{
	ofstream f("register.txt", ios_base::out);
	f << snils_ << ':' << date_.return_day() << '.' << date_.return_month() << '.' << date_.return_year() << '|';
	for (short c : cab_)
	{
		f << c << ',';
	}
	f << '*';

	f.close();
}

void Register::show_register()
{
	cout << "The SNILS: " << snils << endl;
	for (auto s : date_cabinet)
	{
		Date temp = s.first;
		temp.show_date();
		cout << " : ";
		for (short cab : s.second)
		{
			cout << cab << ", ";
		}
		cout << endl;
	}
}


