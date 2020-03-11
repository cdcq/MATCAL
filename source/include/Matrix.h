
#ifndef MATCAL_MATRIX_H
#define MATCAL_MATRIX_H

#include"Fraction.h"
#include<map>
#include<string>

using namespace std;

class Matrix {
public:

	int n, m;
	map<int, map<int, Fraction> > mat;
	int errInfo;
	string name;

	Matrix();
	Matrix(int row, int column);
	Matrix(int dim, Fraction x);
	Matrix(int dim, Fraction diag[]);

	friend Matrix operator*(Matrix A, Matrix B);
	friend Matrix operator*(Fraction x, Matrix A);
	friend Matrix operator*(Matrix A, Fraction x);
	friend Matrix operator+(Matrix A, Matrix B);
	friend Matrix operator-(Matrix A, Matrix B);

	void swapR(int row1, int row2);
	void swapC(int column1, int column2);
	void turn();
	
	void clear();
	void print();

};



#endif


