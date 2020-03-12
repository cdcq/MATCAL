
#include"../include/Fraction.h"

Fraction fra_0;

int Fraction::gcd(int num1, int num2) {
	return num2 ? gcd(num2, num1 % num2) : abs(num1); 
}

Fraction::Fraction() {
	a = 0;
	b = 1;
}
Fraction::Fraction(int _a, int _b) {
	int _d = gcd(_a, _b);
	a = _a / _d;
	b = _b / _d;
	if (b < 0) {
		a = -a;
		b = -b;
	}
}
Fraction::Fraction(int _a) {
	a = _a;
	b = 1;
}

Fraction operator+(Fraction num1, Fraction num2) {
	Fraction num3(num1.a * num2.b + num2.a * num1.b, num1.b * num2.b);
	return num3;
}
Fraction operator-(Fraction num1, Fraction num2) {
	Fraction num3(num1.a * num2.b - num2.a * num1.b, num1.b * num2.b);
	return num3;
}
Fraction operator*(Fraction num1, Fraction num2) {
	Fraction num3(num1.a * num2.a, num1.b * num2.b);
	return num3;
}
Fraction operator/(Fraction num1, Fraction num2) {
	if (num2.a == 0) {
		throw 0;
	}
	Fraction num3(num1.a * num2.b, num1.b * num2.a);
	return num3;
}
Fraction operator+(int num1, Fraction num2) {
	Fraction num3(num1, 1);
	return num3 + num2;
}
Fraction operator-(int num1, Fraction num2){
	Fraction num3(num1, 1);
	return num3 - num2;
}
Fraction operator*(int num1, Fraction num2){
	Fraction num3(num1, 1);
	return num3 * num2;
}
Fraction operator/(int num1, Fraction num2){
	Fraction num3(num1, 1);
	return num3 / num2;
}
Fraction operator+(Fraction num1, int num2){
	return num2 + num1;
}
Fraction operator-(Fraction num1, int num2){
	return num2 - num1;
}
Fraction operator*(Fraction num1, int num2){
	return num2 * num1;
}
Fraction operator/(Fraction num1, int num2){
	return num2 / num1;
}
void Fraction::operator+=(Fraction num1) {
	Fraction num3(a * num1.b + b * num1.a, b * num1.b);
	a = num3.a;
	b = num3.b;
}

void Fraction::print() {
	if (b == 1) {
		printf("%d ", a);
	}
	else {
		printf("%d/%d ", a, b);
	}
}
void Fraction::print(int len) {
	if (b == 1) {
		printf("%*d ", len, a);
	}
	else {
		int count = 0;
		int temb = b;
		for (; temb > 0; temb /= 10) {
			count++;
		}
		printf("%*d/%d ", len - count - 1, a, b);
	}
}
int Fraction::length() {
	int count = 0;
	int tema = a;
	int temb = b;
	if (tema < 0) {
		count++;
		tema = -tema;
	}
	for (; tema > 0; tema /= 10) {
		count++;
	}
	if (temb != 1) {
		count++;
		for (; temb > 0; temb /= 10) {
			count++;
		}
	}
	return count;
}

