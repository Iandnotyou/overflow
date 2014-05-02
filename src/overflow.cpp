//============================================================================
// Name        : overflow.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

template <typename T>
T check_overflow(T a, T b) {
	T _a = a >> 8, _b = b >> 8;

	//
	T overflow_bit = 0;
	if ( a & 0xff + b & 0xff > 0xff)
		overflow_bit = 1;

	if ((_a + _b + overflow_bit) > (std::numeric_limits<T>::max() >> 8) )
		throw std::overflow_error("addition overflow");

}


int main() {

	int a, b;
	a = b = std::numeric_limits<int>::max();

    a = b /= 2;
    check_overflow(a,b);

    a = b <<= 1;

	try {
		check_overflow(a,b);
    } catch (string &e) {
		cerr << e << endl;
	}

	return 0;
}
