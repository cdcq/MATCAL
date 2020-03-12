
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

	int gcd(int num1, int num2);

	friend Fraction operator+(Fraction num1, Fraction num2);
	friend Fraction operator-(Fraction num1, Fraction num2);
	friend Fraction operator*(Fraction num1, Fraction num2);
	friend Fraction operator/(Fraction num1, Fraction num2);
	friend Fraction operator+(int num1, Fraction num2);
	friend Fraction operator-(int num1, Fraction num2);
	friend Fraction operator*(int num1, Fraction num2);
	friend Fraction operator/(int num1, Fraction num2);
	friend Fraction operator+(Fraction num1, int num2);
	friend Fraction operator-(Fraction num1, int num2);
	friend Fraction operator*(Fraction num1, int num2);
	friend Fraction operator/(Fraction num1, int num2);
	void operator+=(Fraction num1);

	void print();
	void print(int len);
	int length();
};

extern Fraction fra_0;

#endif

