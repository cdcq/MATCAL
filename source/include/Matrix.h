
#ifndef MATCAL_MATRIX_H
#define MATCAL_MATRIX_H

#include"Fraction.h"
#include<algorithm>
#include<map>
#include<string>
#include<vector>

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
	void mulR(int row, Fraction num);
	void addR(int row1, int row2, Fraction num);
	void turn();
	int invPair(vector<int> vec);
	Fraction det();
	Matrix inv();
	
	void clear();
	void print();

};



#endif


