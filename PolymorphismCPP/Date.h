#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "IComparable.h"
#include "IPrintable.h"
using namespace std;

class Date:public IComparable<Date>,public IPrintable<Date>  {

	friend bool leap_check(int );
	friend double strToNum(char*s);

public:
	Date(int = 1, int = 1, int = 0);
	//copy C'tor
	Date(const Date&);
	virtual ~Date() {};
	bool setDate(int d, int m, int y);
	bool setDay(int day = 1);
	bool setMonth(int month = 1);
	bool setYear(int year = 0);
	int getDay() const;
	int getMonth()const;
	int getYear()const;
	bool vadality_check() ;
	virtual void print_obj(ostream &out) const;
	virtual void scan_obj();
	char* getProblem();
	//operator overloading//
	virtual bool operator ==(const Date &obj)const;
	virtual bool operator >=(const Date &obj)const;
	virtual bool operator <=(const Date &obj)const;
	virtual bool operator !=(const Date &obj)const;
	virtual bool operator <(const Date &obj)const;
	virtual bool operator >(const Date &obj)const;

private:
	int day, month, year;
	bool valid;
	char problem[100];
};