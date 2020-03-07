#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

class Matrix{
public:

	int n,m;
	map<int,map<int,double> > mat;
	int errInfo;

	Matrix(int row, int column);
	Matrix(int dim, double x);
	Matrix(int dim, double diag[]);

	friend Matrix operator*(Matrix A, Matrix B);
	friend Matrix operator*(double x, Matrix A);
	friend Matrix operator*(Matrix A, double x);

	void clear();

};

Matrix::Matrix(int row, int column){
	n=row, m=column;
	clear();
	errInfo = 0;
}
Matrix::Matrix(int dim, double x){
	n=dim, m=dim;
	clear();
	for(int i=1;i<=n;++i)
		mat[i][i]=x;
	errInfo = 0;
}
Matrix::Matrix(int dim, double diag[]){
	n=dim, m=dim;
	clear();
	for(int i=1;i<=n;++i)
		mat[i][i]=diag[i];
	errInfo = 0;
}

Matrix operator*(Matrix A, Matrix B){
	Matrix C(A.n, B.m);
	if(A.m != B.n){
		C.errInfo = 1;
		return C;
	}

	for(int i=1;i<=A.n;++i)
		for(int j=1;j<=B.m;++j)
			for(int k=1;k<=A.m;++k)
				C.mat[i][j]+=A.mat[i][k]*B.mat[k][j];
	return C;
}
Matrix operator*(double x, Matrix A){
	Matrix C=A;
	for(int i=1;i<=A.n;++i)
		for(int j=1;j<=A.m;++j)
			C.mat[i][j]=A.mat[i][j]*x;
	return C;
}
Matrix operator*(Matrix A, double x){
	return x*A;
}

void Matrix::clear(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			mat[i][j]=0;
}

