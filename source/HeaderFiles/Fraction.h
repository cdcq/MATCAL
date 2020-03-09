
#ifndef MATCAL_FRACTION_H
#define MATCAL_FRACTION_H

#include<cstdio>
#include<cmath>

class Fraction {
public:
	int a, b;

	Fraction();
	Fraction(int _a, int _b);
	Fraction(int _a);

	void print();
	int gcd(int num1, int num2);

	friend Fraction operator+(Fraction num1, Fraction num2);
	friend Fraction operator-(Fraction num1, Fraction num2);
	friend Fraction operator*(Fraction num1, Fraction num2);
	friend Fraction operator/(Fraction num1, Fraction num2);
	void operator+=(Fraction num1);

};

extern Fraction fra_0;

#endif

