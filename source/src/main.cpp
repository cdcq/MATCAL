
#include"../include/main.h"

Main mainClass;

int main() {
	mainClass.init();

	while (mainClass.work());
	
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

	if (inputInfo == 0) {
		return false;
	}
	else if (inputInfo == 1) {
	}
	else if (inputInfo == 2) {
		inputS.erase(0, 4);
		string matName = inputS;
		matSet.matInput(matName);
		return true;
	}
	else if (inputInfo == 3) {
		inputS.erase(0, 6);
		string matName = inputS;
		if (matSet.set.count(matName) == 1) {
			matSet.set[matName].print();
			return true;
		}
		else {
			error.throwError(-200);
			return true;
		}
	}
	else if (inputInfo == 4) {
		inputS.erase(0, 4);
		string matName = inputS;
		if (matSet.set.count(matName) == 1) {
		}
		else {
			error.throwError(-200);
			return true;
		}
	}
	else if (inputInfo == 5 || inputInfo == 6) {
		inputS.erase(0, 6);
		int temParSet[7] = { 0, 1, 0, 2, 0, -2, 0 };
		if (!lexAna.RecPar(inputS, temParSet, 7)) {
			error.throwError(-3);
			return true;
		}

		unsigned int pos = 0;
		string matName = strProc.getStr(inputS, pos);
		if (matSet.set.count(matName) != 1) {
			error.throwError(-200);
			return true;
		}

		int num1 = strProc.getInt(inputS, pos);
		int num2 = strProc.getInt(inputS, pos);

		if (inputInfo == 5) {
			matSet.set[matName].swapR(num1, num2);
		}
		else if(inputInfo == 6) {
			matSet.set[matName].swapC(num1, num2);
		}

	}
	else {
		error.throwError(-1);
		//int exprInfo = exprCalc.cal(inputS);
		return true;
	}

	return true;
}