
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
		unsigned int pos = 0;
		for (; pos < inputS.length() && islower(inputS[pos]); pos++);
		string matName = inputS.substr(0, pos);
		if (matSet.set.count(matName) != 1) {
			error.throwError(-200);
			return true;
		}
		if (pos == inputS.length() || inputS[pos] != ' ') {
			error.throwError(-3);
			return true;
		}
		inputS.erase(0, pos + 1);
		pos = 0;

		int num1 = strProc.getInt(inputS, pos, 1);
		if (pos == -1) {
			error.throwError(-3);
			return true;
		}
		int num2 = strProc.getInt(inputS, pos, 1);
		if (pos == -1) {
			error.throwError(-3);
			return true;
		}
		for (; pos <= inputS.length() && inputS[pos] == ' '; pos++);
		if (pos != inputS.length()) {
			error.throwError(-3);
			return true;
		}

		if (inputInfo == 5) {
			matSet.set[matName].swapR(num1, num2);
		}
		else if(inputInfo) {
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