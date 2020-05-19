#pragma once
#include "IPrintable.h"
using namespace std;


template<class T>
class Interval{
	T a, b;
	bool valid;
public:
	Interval(const T&, const T&);
	Interval(const Interval&);
	~Interval() {};

	bool isEmpty()const;
	bool isBefore(const Interval<T>&)const;
	bool isAfter(const Interval<T>&)const;
	bool intersects(const Interval<T>&)const;
	bool contains(const T&)const;
	bool vadality_check() const;
	bool isValid(const T &setA, const T &setB);
	/*
	char* getProblem();
	*/
	//operator overloading//
	Interval<T> operator&&(const Interval<T>&) const;
	Interval<T> operator||(const Interval<T>&) const;
private:
	friend ostream& operator<<(ostream& out, const Interval<T>&other) {
		if (other.vadality_check())
		{
			out << "(" << other.a << ", " << other.b << ")";
		}
		else if(other.a ==other.b )
		{
			out << "EMPTY";
		}
		else
			out << "Invalid interval";
		return out;
	}
};

template<class T>
Interval<T>::Interval(const T &setA, const T &setB) :a(setA), b(setB) {
	this->valid = isValid(setA,setB);
};

template<class T>
Interval<T>::Interval(const Interval<T>& cp) {
	this->a = cp.a;
	this->b = cp.b;
}

template<class T>
bool Interval<T>::isEmpty() const
{
	if (a == b)
		return true;
	return false;
}

template<class T>
bool Interval<T>::isBefore(const Interval<T>&other) const
{
	if (this->b <= other.a && (this->a!=this->b ) )
		return true;
	return false;
}

template<class T>
bool Interval<T>::isAfter(const Interval<T>&other) const
{
	if (this->a > other.b)
		return true;
	return false;
}

template<class T>
bool Interval<T>::intersects(const Interval<T>&other) const
{
	if ((other.b>this->a) && (other.a<this->b))
		return true;
	return false;
}

template<class T>
bool Interval<T>::contains(const T &other) const
{
	if (a<other && b>other)
		return true;
	return false;
}

template<class T>
bool Interval<T>::vadality_check()  const
{ 
	if (a < b)
		return true;
	return false;
}

template<class T>
bool Interval<T>::isValid(const T &A, const T &B)
{
	if (A>B)
		return false;
	return true;
}


template<class T>
Interval<T> Interval<T>::operator&&(const Interval<T>&other) const
{
	if (this->intersects(other))
	{
		if(other.a > this->a) //first state
		return Interval<T>(other.a, this->b);
		else //other.a <= this->a
			return Interval<T>(this->a, other.b);
	}
	else //TODO:check it
	{
		return Interval<T>(a,a);
	}
}

template<class T>
Interval<T> Interval<T>::operator||(const Interval<T>&other) const
{
	//TODO: check if this and other same type.
	//if they are diff-->isValid=0; 
	Interval<T> temp = *this;
	if (this->intersects(other))
	{
	this->a < other.a ? temp.a = this->a : temp.a = other.a;
	this->b > other.b ? temp.b = this->b : temp.b = other.b;
	return temp;
	}
	else
		return Interval<T>(b, a);
}
