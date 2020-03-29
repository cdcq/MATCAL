
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
void Matrix::mulR(int row, Fraction num) {
	for (int i = 1; i <= m; i++) {
		mat[row][i] = mat[row][i] * num;
	}
}
void Matrix::addR(int row1, int row2, Fraction num) {
	for (int i = 1; i <= m; i++) {
		mat[row2][i] = mat[row2][i] + mat[row1][i] * num;
	}
}
Matrix Matrix::turn() {
	Matrix temMat(m, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temMat.mat[j][i] = mat[i][j];
		}
	}
	return temMat;
}
int Matrix::invPair(vector<int> vec) {
	int count = 0;
	for (unsigned int i = 0; i < vec.size(); i++) {
		for (unsigned int j = i + 1; j < vec.size(); j++) {
			if (vec[i] > vec[j]) {
				count++;
			}
		}
	}
	return count;
}
Fraction Matrix::det() {
	if (m != n) {
		throw - 206;
	}
	vector<int> perm;
	int mul = 1;
	for (int i = 1; i <= n; i++) {
		perm.push_back(i);
		mul = mul * i;
	}
	Fraction detSum;
	for (int k = 1; k <= mul; k++) {
		Fraction temMul(1, 1);
		if (invPair(perm) & 1) {
			temMul.a = -1;
		}
		for (int i = 1; i <= n; i++) {
			temMul = temMul * mat[i][perm[i - 1]];
		}
		detSum = detSum + temMul;
		next_permutation(perm.begin(), perm.end());
	}
	return detSum;
}
Matrix Matrix::inv() {
	if (det().a == 0) {
		throw - 207;
	}
	Matrix temMat(n, m * 2);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temMat.mat[i][j] = mat[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		temMat.mat[i][m + i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (temMat.mat[i][i].a == 0) {
			int temR = i;
			for (int j = i + 1; j <= n; j++) {
				if (temMat.mat[j][i].a != 0) {
					temR = j;
					break;
				}
			}
			if (temR == i) {
				throw - 207;
			}
			temMat.swapR(i, temR);
		}
		Fraction temFra = temMat.mat[i][i];
		swap(temFra.a, temFra.b);
		temMat.mulR(i, temFra);
		for (int j = i + 1; j <= n; j++) {
			temMat.addR(i, j, -1 * temMat.mat[j][i]);
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = i - 1; j >= 1; j--) {
			temMat.addR(i, j, -1 * temMat.mat[j][i]);
		}
	}
	Matrix ansMat(n, m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ansMat.mat[i][j] = temMat.mat[i][m + j];
		}
	}
	return ansMat;
}
Matrix Matrix::ref() {
	Matrix temMat(n, m);
	temMat.mat = mat;
	for (int i = 1; i <= n; i++) {
		if (temMat.mat[i][i].a == 0) {
			int temR = 0;
			for (int j = i + 1; j <= n; j++) {
				if (temMat.mat[j][i].a != 0) {
					temR = j;
					break;
				}
			}
			if (temR == 0) {
				continue;
			}
			temMat.swapR(i, temR);
		}
		Fraction temFra = temMat.mat[i][i];
		swap(temFra.a, temFra.b);
		for (int j = i + 1; j <= n; j++) {
			temMat.addR(i, j, -1 * temMat.mat[j][i] * temFra);
		}
	}
	return temMat;
}
int Matrix::rank() {
	Matrix temMat(n, m);
	temMat.mat = mat;
	temMat = temMat.ref();

	int count = 0;
	for (int i = n; i >= 1; i--) {
		bool temMark = true;
		for (int j = 1; j <= m; j++) {
			if (temMat.mat[i][j].a != 0) {
				temMark = false;
				break;
			}
		}
		if (!temMark) {
			break;
		}
		else {
			count++;
		}
	}
	return n - count;
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

