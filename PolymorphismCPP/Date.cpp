#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <math.h>
using namespace std;

Date::Date(int i, int j, int k) :day(i),month(j),year(k)
{
	if (vadality_check())
		valid = true; // set flag as true,then check if its valid.
	else
		valid = false;
}
Date::Date(const Date &d)
{
	this->year = d.year;
	this->month = d.month;
	this->day = d.day;
}
bool Date::setDate(int d, int m, int y)
{
	if ( (setDay(d) == false) || (setMonth(m) == false) || (setYear(y) == false) )
	return false;
	else
	{
	setDay(day);
	setMonth(month);
	setYear(year);
	}
	return true;
}

bool Date::setDay(int in_day)
{
	if (in_day >= 1 && in_day <= 31) {
		day = in_day;
		return true;
	}
	cout << "Invalid day: " << in_day << endl;
	return false;
}

bool Date::setMonth(int in_month)
{
	if (in_month >= 1 && in_month <= 12)
	{
		month = in_month; 
		return true;
	}
	cout << "Invalid month : " << in_month << endl;
	return false;
}

bool Date::setYear(int in_year)
{
	if (in_year >= 0) 
	{
		year = in_year;
		if (vadality_check())
			this->valid = true;
		else
			this->valid =false;
		return true;
	} 
	else
	{
	cout << "Invalid year: "<< in_year << endl;
	return false;
	}
}


bool leap_check(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Date::vadality_check() 
{
	
	switch (month)
	{
	case 2:
		if (leap_check(year))
		{
			if (day >= 1 && day <= 29)
			{
				return true;
			}
			else
			{
				this->valid = 0;
				strcpy(this->problem, "Illegal day for month");
				return false;
			}
		}
		else  //Not a leap year
		{
			if (day >= 1 && day <= 28)
			{
				return true;
			}
			else
			{
				this->valid = 0;
				strcpy(this->problem, "Not a leap year");
				return false;
			}
		}
	case 4:
	case 11:
		if (day >= 1 && day <= 30)
		{
			return true;
		}
		else
		{
			this->valid = 0;
			strcpy(this->problem, "Illegal day for month");
			return false;
		}

	case 1:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 12:
		if (day >= 1 && day <= 31)
		{
			return true;
		}
		else
		{
			this->valid = 0;
			strcpy(this->problem, "Illegal day for month");
			return false;
		}
	
	default:
		this->valid = 0;
		strcpy(this->problem, "Illegal month");
		return false;
	
	}
	
}

double strToNum(char * s)
{
	int i;
	double num = 0;
	double mul = pow(10, strlen(s)-1);
	for(i=0;s[i]!='\0';i++)
	{
		num += (s[i] - '0')*mul;
		mul /= 10;
	}
	return num;
}

void Date::print_obj(ostream &out) const
{

	if (valid)
	{
		if (day < 10)
			out << '0' << day <<'/';
		else
			out << day << '/';
		if (month < 10)
			out << '0' << month;
		else
			out << month;
		out << '/' << year;
	}
	else
	{
		cout << problem;
	}
	
}

void Date::scan_obj()
{
	char *str = (char*)malloc(100);
	char d[10], m[10], ye[10];
	int i = 0, j = 0;
	scanf("%s", str);

	if (str[j] == '-')
	{
		this->valid = false;
		strcpy(this->problem, "Illegal day for month");
		this->day = 0;
		this->month = 0;
		this->year = 0;
		delete[] str;
		return;
	}
	while ((str[j] != '/'))
	{
		d[i++] = str[j++];
	}
	d[i] = '\0';
	this->day = (int)strToNum(d);
	j++;
	//
	if (str[j] == '-')
	{
		this->valid = false;
		strcpy(this->problem, "Illegal month");
		this->day = 0;
		this->month = 0;
		this->year = 0;
		delete[] str;
		return;
	}
	for (i = 0; str[j] != '/'; i++)
	{
		m[i] = str[j++];
	}
	m[i] = '\0';
	this->month = (int)strToNum(m);
	j++;
	//
	if (str[j] == '-')
	{
		this->valid = false;
		strcpy(this->problem, "Illegal year");
		this->day = 0;
		this->month = 0;
		this->year = 0;
		delete[] str;
		return;
	}
	for (i = 0; str[j] != '\0'; i++)
	{
		ye[i] = str[j++];
	}
	ye[i] = '\0';
	this->year = (int)strToNum(ye);
	
		if (vadality_check())
		{
			this->valid = true;
		}
		else
		{
			//cout << "the date is not valid" << endl;
			valid = false;
		}
		delete[] str;
	
}

char * Date::getProblem()
{
	return this->problem;
}




int Date::getDay()const
{
	return day;
}

int Date::getMonth()const
{
	return month;
}

int Date::getYear()const
{
	return year;
}


//operator overloading functions body//
bool Date::operator==(const Date & d) const
{
	if ((this->year == d.year)&&(this->month == d.month)&&(this->day == d.day))
		return true;
	return false;
}


bool Date::operator<=(const Date & d) const
{
	//this function return true if this date<=other date
	if (*this == d)
		return true;
	return *this < d;
}
bool Date::operator!=(const Date & d) const
{
	return !((*this) == d);
}
bool Date::operator>=(const Date & d) const
{
	if (*this == d)
		return true;
	else
		return *this > d;
}
bool Date::operator<(const Date & d) const
{
	if (this->year < d.year)
		return true;
	else if (this->year == d.year)
	{
		if (this->month < d.month)
			return true;
		else if (this->month == d.month)
			return this->day < d.day;
		else // (this->month > d.month) && same year
			return false;
	}
	else // this->year > d.year
		return false;
}

bool Date::operator>(const Date & d) const
{
	return !(*this < d);
}

