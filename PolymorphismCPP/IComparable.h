#pragma once
template<class T>
class IComparable {
public:
	virtual bool operator ==(const T &obj)const = 0;
	virtual bool operator >=(const T &obj)const = 0;
	virtual bool operator <=(const T &obj)const = 0;
	virtual bool operator !=(const T &obj)const = 0;
	virtual bool operator >(const T &obj)const = 0;
	virtual bool operator <(const T &obj)const = 0;
	virtual ~IComparable()=0;
};

template<class T>
IComparable<T>::~IComparable() {};