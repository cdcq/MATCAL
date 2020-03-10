
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
		printf("详细的使用方法请见《使用文档》\n");
		printf("（还没想好怎么写help = =b）\n");
		return true;
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
	else if (inputInfo == 7 || inputInfo == 8 || inputInfo == 9) {
		inputS.erase(0, 4);
		int temParSet[7] = { 0, 1, 0, 1, 0, -1, 0 };
		if (!lexAna.RecPar(inputS, temParSet, 7)) {
			error.throwError(-3);
			return true;
		}
		
		unsigned pos = 0;
		string matName1 = strProc.getStr(inputS, pos);
		string matName2 = strProc.getStr(inputS, pos);
		string matName3 = strProc.getStr(inputS, pos);

		if (matSet.set.count(matName1) != 1) {
			Matrix temMat;
			matSet.set[matName1] = temMat;
		}
		if (matSet.set.count(matName2) != 1) {
			error.throwError(-200);
			return true;
		}
		if (matSet.set.count(matName3) != 1) {
			error.throwError(-200);
			return true;
		}

		try {
			if (inputInfo == 7) {
				matSet.set[matName1] = matSet.set[matName2] * matSet.set[matName3];
			}
			else if (inputInfo == 8) {
				matSet.set[matName1] = matSet.set[matName2] + matSet.set[matName3];
			}
			else if (inputInfo == 9) {
				matSet.set[matName1] = matSet.set[matName2] - matSet.set[matName3];
			}
		}
		catch(int errorInfo){
			error.throwError(errorInfo);
		}
	}
	else {
		error.throwError(-1);
		return true;
	}

	return true;
}