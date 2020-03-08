
#ifndef MATCAL_FRACTION_H
#define MATCAL_FRACTION_H

#include<cmath>

int gcd(int a,int b){  return b ? gcd(b,a%b) : abs(a);}

class Fraction{
public:
	int a,b;

	Fraction();
	Fraction(int _a, int _b);
	Fraction(int _a);

	void print();

	friend Fraction operator+(Fraction num1, Fraction num2);
	friend Fraction operator-(Fraction num1, Fraction num2);
	friend Fraction operator*(Fraction num1, Fraction num2);
	friend Fraction operator/(Fraction num1, Fraction num2);
	void operator+=(Fraction num1);

};
Fraction fra_0;

void Fraction::print(){
	if(b == 1){
		printf("%d ", a);
	}
	else{
		printf("%d/%d ", a, b);
	}
}

Fraction::Fraction(){
	a = 0;
	b = 1;
}
Fraction::Fraction(int _a, int _b){
	int _d = gcd(_a, _b);
	a = _a/_d;
	b = _b/_d;
	if(b < 0){
		a = -a;
		b = -b;
	}
}
Fraction::Fraction(int _a){
	a = _a;
	b = 1;
}

Fraction operator+(Fraction num1, Fraction num2){
	Fraction num3(num1.a*num2.b + num2.a*num1.b, num1.b*num2.b);
	return num3;
}
Fraction operator-(Fraction num1, Fraction num2){
	return num1 - num2;
}
Fraction operator*(Fraction num1, Fraction num2){
	Fraction num3(num1.a*num2.a, num1.b*num2.b);
	return num3;
}
Fraction operator/(Fraction num1, Fraction num2){
	Fraction num3(num1.a*num2.b, num1.b*num2.a);
	return num3;
}
void Fraction::operator+=(Fraction num1){
	Fraction num3(a*num1.b + b*num1.a, b*num1.b);
	a = num3.a;
	b = num3.b;
}

#endif


