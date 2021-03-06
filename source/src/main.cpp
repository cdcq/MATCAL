
#include"../include/main.h"

Main mainClass;

int main() {
	mainClass.init();

	for (;;) {
		try {
			if (!mainClass.work()) {
				return 0;
			}
		}
		catch (int errInfo) {
			error.throwError(errInfo);
		}
	}

	return 0;
}


void Main::init() {
	launchInfo.printInfo();
}

bool Main::work() {
	printf(">> ");

	string inputS;
	getline(cin, inputS);
	if (inputS.length() == 0) {
		return true;
	}

	inputS = toLower(inputS);
	int inputInfo = input.inputAnalyse(inputS);
	if (inputInfo == -1) {
		throw - 1;
	}
	inputS.erase(0, input.tempStr[inputInfo].length());

	if (inputInfo == 0) {
		return false;
	}
	else if (inputInfo == 1) {
		printf("详细的使用方法请见《使用文档》\n");
		printf("（还没想好怎么写help = =b）\n");
		printf("文档下载地址：https:\/\/cdcq.coding.net\/s\/0f99a33c-5978-4fc7-b8ea-254ec6e1a731\n");
	}
	else if (inputInfo == 2) {
		execInput(inputS, inputInfo);
	}
	else if (inputInfo == 3) {
		execPrint(inputS, inputInfo);
	}
	else if (inputInfo == 4) {
		execInv(inputS, inputInfo);
	}
	else if (inputInfo == 5 || inputInfo == 6) {
		execSwap(inputS, inputInfo);
	}
	else if (inputInfo == 7 || inputInfo == 8 || inputInfo == 9) {
		execOper(inputS, inputInfo);
	}
	else if (inputInfo == 10) {
		execTurn(inputS, inputInfo);
	}
	else if (inputInfo == 11) {
		execDet(inputS, inputInfo);
	}
	else if (inputInfo == 12) {
		execRank(inputS, inputInfo);
	}
	else if (inputInfo == 13) {
		execRef(inputS, inputInfo);
	}
	else if (inputInfo == 14) {
		execClr(inputS, inputInfo);
	}
	else {
		throw - 1;
	}

	return true;
}

void Main::execInput(string inputS, int inputInfo) {
	int temParSet[3] = { 0, -1, 0 };
	if (!lexAna.RecPar(inputS, temParSet, 3)) {
		throw - 3;
	}
	string matName = inputS;
	matSet.matInput(matName);
}

void Main::execPrint(string inputS, int inputInfo) {
	int temParSet[3] = { 0, -1, 0 };
	if (!lexAna.RecPar(inputS, temParSet, 3)) {
		throw - 3;
	}
	string matName = inputS;
	if (matSet.set.count(matName) != 1) {
		throw - 200;
	}
	matSet.set[matName].print();
}

void Main::execSwap(string inputS, int inputInfo) {
	int temParSet[7] = { 0, 1, 0, 2, 0, -2, 0 };
	if (!lexAna.RecPar(inputS, temParSet, 7)) {
		throw - 3;
	}

	unsigned int pos = 0;
	string matName = strProc.getStr(inputS, pos);
	if (matSet.set.count(matName) != 1) {
		throw - 200;
	}

	int num1 = strProc.getInt(inputS, pos);
	int num2 = strProc.getInt(inputS, pos);

	if (inputInfo == 5) {
		matSet.set[matName].swapR(num1, num2);
	}
	else if (inputInfo == 6) {
		matSet.set[matName].swapC(num1, num2);
	}
}

void Main::execOper(string inputS, int inputInfo) {
	int temParSet[7] = { 0, 1, 0, 1, 0, -1, 0 };
	string matName1;
	string matName2;
	string matName3;
	unsigned pos = 0;
	if (!lexAna.RecPar(inputS, temParSet, 7)) {
		int temParSet2[5] = { 0, 1, 0, -1 , 0 };
		if (!lexAna.RecPar(inputS, temParSet2, 5)) {
			throw - 3;
		}
		matName2 = strProc.getStr(inputS, pos);
		matName3 = strProc.getStr(inputS, pos);
	}
	else {
		matName1 = strProc.getStr(inputS, pos);
		matName2 = strProc.getStr(inputS, pos);
		matName3 = strProc.getStr(inputS, pos);
	}

	if (matName1.length() > 0 && matSet.set.count(matName1) != 1) {
		Matrix temMat;
		matSet.set[matName1] = temMat;
	}
	if (matSet.set.count(matName2) != 1) {
		throw - 200;
	}
	if (matSet.set.count(matName3) != 1) {
		throw - 200;
	}

	Matrix temMat;
	if (inputInfo == 7) {
		temMat = matSet.set[matName2] * matSet.set[matName3];
	}
	else if (inputInfo == 8) {
		temMat = matSet.set[matName2] + matSet.set[matName3];
	}
	else if (inputInfo == 9) {
		temMat = matSet.set[matName2] - matSet.set[matName3];
	}
	if (matName1.length() == 0) {
		temMat.print();
	}
	else {
		matSet.set[matName1] = temMat;
	}
}

void Main::execTurn(string inputS, int inputInfo) {
	int temParSet[5] = { 0, 1, 0, -1, 0 };
	string matName1;
	string matName2;
	unsigned int pos = 0;
	if (!lexAna.RecPar(inputS, temParSet, 5)) {
		int temParSet2[3] = { 0, -1, 0 };
		if (!lexAna.RecPar(inputS, temParSet2, 3)) {
			throw - 3;
		}
		matName2 = strProc.getStr(inputS, pos);
	}
	else {
		matName1 = strProc.getStr(inputS, pos);
		matName2 = strProc.getStr(inputS, pos);
	}

	if (matName1.length() > 0 && matSet.set.count(matName1) != 1) {
		Matrix temMat;
		matSet.set[matName1] = temMat;
	}
	if (matSet.set.count(matName2) != 1) {
		throw - 200;
	}

	if (matName1.length() == 0) {
		matSet.set[matName2].turn().print();
	}
	else {
		matSet.set[matName1] = matSet.set[matName2].turn();
	}

}

void Main::execDet(string inputS, int inputInfo) {
	int temParSet[3] = { 0, -1, 0 };
	if (!lexAna.RecPar(inputS, temParSet, 3)) {
		throw - 3;
	}

	unsigned int pos = 0;
	string matName = strProc.getStr(inputS, pos);
	if (matSet.set.count(matName) != 1) {
		throw - 200;
	}
	matSet.set[matName].det().print();
	printf("\n");
}

void Main::execInv(string inputS, int inputInfo) {
	int temParSet[5] = { 0, 1, 0, -1, 0 };
	string matName1;
	string matName2;
	unsigned int pos = 0;
	if (!lexAna.RecPar(inputS, temParSet, 5)) {
		int temParSet2[3] = { 0, -1, 0 };
		if (!lexAna.RecPar(inputS, temParSet2, 3)) {
			throw - 3;
		}
		matName2 = strProc.getStr(inputS, pos);
	}
	else {
		matName1 = strProc.getStr(inputS, pos);
		matName2 = strProc.getStr(inputS, pos);
	}

	if (matName1.length() > 0 && matSet.set.count(matName1) != 1) {
		Matrix temMat;
		matSet.set[matName1] = temMat;
	}
	if (matSet.set.count(matName2) != 1) {
		throw - 200;
	}

	if (matName1.length() == 0) {
		matSet.set[matName2].inv().print();
	}
	else {
		matSet.set[matName1] = matSet.set[matName2].inv();
	}

}

void Main::execRank(string inputS, int inputInfo) {
	int temParSet[3] = { 0, -1, 0 };
	if (!lexAna.RecPar(inputS, temParSet, 3)) {
		throw - 3;
	}

	unsigned int pos = 0;
	string matName = strProc.getStr(inputS, pos);
	if (matSet.set.count(matName) != 1) {
		throw - 200;
	}
	printf("%d\n", matSet.set[matName].rank());
}

void Main::execRef(string inputS, int inputInfo) {
	int temParSet[3] = { 0, -1, 0 };
	if (!lexAna.RecPar(inputS, temParSet, 3)) {
		throw - 3;
	}

	unsigned int pos = 0;
	string matName = strProc.getStr(inputS, pos);
	if (matSet.set.count(matName) != 1) {
		throw - 200;
	}
	matSet.set[matName].ref().print();
}

void Main::execClr(string inputS, int inputInfo) {
	do {
		printf("警告：危险操作！是否清除所有矩阵？\n（Y/N）");
		getline(cin, inputS);
		if (inputS[0] == 'Y')  inputS[0] = 'y';
		if (inputS[0] == 'N')  inputS[0] = 'n';
	} while (inputS.length() == 0 || (inputS[0] != 'y' && inputS[0] != 'n'));
	if (inputS[0] == 'n') {
		return;
	}
	else {
		matSet.set.clear();
	}
}

