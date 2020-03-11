
#include"../include/Matrix.h"

Matrix::Matrix() {
	n = 0;
	m = 0;
	clear();
	errInfo = 0;
}
Matrix::Matrix(int row, int column) {
	n = row;
	m = column;
	clear();
	errInfo = 0;
}
Matrix::Matrix(int dim, Fraction x) {
	n = dim;
	m = dim;
	clear();
	for (int i = 1; i <= n; i++) {
		mat[i][i] = x;
	}
	errInfo = 0;
}
Matrix::Matrix(int dim, Fraction diag[]) {
	n = dim;
	m = dim;
	clear();
	for (int i = 1; i <= n; i++) {
		mat[i][i] = diag[i];
	}
	errInfo = 0;
}

Matrix operator*(Matrix A, Matrix B) {
	Matrix C(A.n, B.m);
	if (A.m != B.n) {
		throw - 204;
	}

	for (int i = 1; i <= A.n; i++) {
		for (int j = 1; j <= B.m; j++) {
			for (int k = 1; k <= A.m; k++) {
				C.mat[i][j] += A.mat[i][k] * B.mat[k][j];
			}
		}
	}
	return C;
}
Matrix operator*(Fraction x, Matrix A) {
	Matrix C = A;
	for (int i = 1; i <= A.n; i++)
		for (int j = 1; j <= A.m; j++)
			C.mat[i][j] = A.mat[i][j] * x;
	return C;
}
Matrix operator*(Matrix A, Fraction x) {
	return x * A;
}
Matrix operator+(Matrix A, Matrix B) {
	if (A.n != B.n || A.m != B.m) {
		throw - 205;
	}
	Matrix C(A.n, A.m);
	for (int i = 1; i <= A.n; i++) {
		for (int j = 1; j <= A.m; j++) {
			C.mat[i][j] = A.mat[i][j] + B.mat[i][j];
		}
	}
	return C;
}
Matrix operator-(Matrix A, Matrix B) {
	if (A.n != B.n || A.m != B.m) {
		throw - 205;
	}
	Matrix C;
	for (int i = 1; i <= A.n; i++) {
		for (int j = 1; j <= A.m; j++) {
			C.mat[i][j] = A.mat[i][j] - B.mat[i][j];
		}
	}
	return C;
}

void Matrix::swapR(int row1, int row2) {
	if (row1 == row2) {
		return;
	}
	for (int i = 1; i <= m; i++) {
		swap(mat[row1][i], mat[row2][i]);
	}
}
void Matrix::swapC(int column1, int column2) {
	if (column1 == column2) {
		return;
	}
	for (int i = 1; i <= n; i++) {
		swap(mat[i][column1], mat[i][column2]);
	}
}
void Matrix::turn() {
	Matrix temMat(m, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temMat.mat[j][i] = mat[i][j];
		}
	}
	mat = temMat.mat;
	swap(n, m);
}

void Matrix::clear() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			mat[i][j] = fra_0;
}
void Matrix::print() {
	int maxLen = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j].length() > maxLen) {
				maxLen = mat[i][j].length();
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mat[i][j].print(maxLen);
		}
		printf("\n");
	}
}

