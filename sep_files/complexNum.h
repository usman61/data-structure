// Header file complexNum.h
#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H

class complexNum {
private:
	int real;
	int imaginary;

public:
	// With default value,
	// default constructor
	complexNum(const int a = 0,
			const int b = 0);

	// setter function
	void setNum(const int a,
				const int b);

	// Prints the complex number
	// in the form real + i(imaginary),
	// i->iota
	void print() const;

	// An overloaded operator to compare
	// two complex number objects
	bool operator==(const complexNum&);
};
#endif
