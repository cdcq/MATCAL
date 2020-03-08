
#ifndef MATCAL_MATRIX_H
#define MATCAL_MATRIX_H

#include"Fraction.h"
#include<map>
#include<string>

using namespace std;

class Matrix{
public:

	int n,m;
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

	void clear();
	void print();

};

Matrix::Matrix(){
	n = 0;
   	m = 0;
	clear();
	errInfo = 0;
}
Matrix::Matrix(int row, int column){
	n = row;
	m = column;
	clear();
	errInfo = 0;
}
Matrix::Matrix(int dim, Fraction x){
	n = dim;
   	m = dim;
	clear();
	for(int i=1 ; i<=n ; i++){
		mat[i][i] = x;
	}
	errInfo = 0;
}
Matrix::Matrix(int dim, Fraction diag[]){
	n = dim;
	m = dim;
	clear();
	for(int i=1 ; i<=n ; i++){
		mat[i][i] = diag[i];
	}
	errInfo = 0;
}

Matrix operator*(Matrix A, Matrix B){
	Matrix C(A.n, B.m);
	if(A.m != B.n){
		C.errInfo = 1;
		return C;
	}

	for(int i=1 ; i<=A.n ; i++)
		for(int j=1 ; j<=B.m ; j++)
			for(int k=1 ; k<=A.m ; k++)
				C.mat[i][j] += A.mat[i][k]*B.mat[k][j];
	return C;
}
Matrix operator*(Fraction x, Matrix A){
	Matrix C = A;
	for(int i=1 ; i<=A.n ; i++)
		for(int j=1 ; j<=A.m ; j++)
			C.mat[i][j] = A.mat[i][j]*x;
	return C;
}
Matrix operator*(Matrix A, Fraction x){
	return x*A;
}

void Matrix::clear(){
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
			mat[i][j] = fra_0;
}
void Matrix::print(){
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j)
			mat[i][j].print();
		printf("\n");
	}
}

#endif


