#pragma once
#include <iostream>
using namespace std;
template<class P>
class IPrintable {

public:
	friend istream& operator>>(istream &in_stream, P& obj) {
		obj.scan_obj();
		return in_stream;
	}
	friend ostream& operator<<(ostream &output_stream, P& obj) {
		obj.print_obj(output_stream);
		return output_stream;
	}
	virtual void scan_obj() = 0;
	virtual void print_obj(ostream &out) const = 0;
	virtual ~IPrintable() = 0;

};
//A class with pure virtual destructors must provide a function body for the pure virtual destructor.//
template<class P>
IPrintable<P>::~IPrintable() {};