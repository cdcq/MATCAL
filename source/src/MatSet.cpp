
#include"../include/MatSet.h"

MatSet matSet;

void MatSet::matInput(string matName) {
	if (matSet.set.count(matName)) {
		error.throwError(-201);
		return;
	}
	Matrix temMat;
	temMat.name = matName;

	string inputS;
	for (;;) {
		getline(cin, inputS);
		if (inputS.length() == 0) {
			break;
		}
		temMat.n++;
		int temCol = 0;
		int temNum[2] = { 0, 1 };
		int denFlag = 0;
		int minusFlag = 1;
		for (unsigned int i = 0; i < inputS.length(); i++) {
			if (inputS[i] == ' ') {
				continue;
			}
			else if (inputS[i] == '-') {
				minusFlag = -1;
			}
			else if (!isdigit(inputS[i])) {
				error.throwError(-202);
				return;
			}
			else {
				Fraction inputNum = strProc.getFra(inputS, i);
				inputNum.a *= minusFlag;
				temCol++;
				temMat.mat[temMat.n][temCol] = inputNum;
			}
		}
		if (temMat.m == 0) {
			temMat.m = temCol;
		}
		else if (temCol != temMat.m) {
			error.throwError(-203);
			return;
		}
	}

	matSet.set[matName] = temMat;
}

