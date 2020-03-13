
#include"../include/InputProcessor.h"

Input input;

Input::Input() {
	tempStr.push_back("exit");
	tempStr.push_back("help");
	tempStr.push_back("mat ");
	tempStr.push_back("print ");
	tempStr.push_back("inv ");
	tempStr.push_back("swapr ");
	tempStr.push_back("swapc ");
	tempStr.push_back("mul ");
	tempStr.push_back("add ");
	tempStr.push_back("sub ");
	tempStr.push_back("turn ");
	tempStr.push_back("det ");
	tempStr.push_back("rank ");
}

bool Input::cmpPre(string tempS, string cmpS) {
	if (tempS.length() < cmpS.length()) {
		return false;
	}
	for (unsigned int i = 0; i < cmpS.length(); i++) {
		if (tempS[i] != cmpS[i]) {
			return false;
		}
	}
	return true;
}

int Input::inputAnalyse(string inputS) {
	for (unsigned int inputInfo = 0; inputInfo < tempStr.size(); inputInfo++) {
		if (cmpPre(inputS, tempStr[inputInfo])) {
			return inputInfo;
		}
	}

	return -1;
}

string toLower(string tempS) {
	for (unsigned int i = 0; i < tempS.length(); i++)
		if (tempS[i] >= 'A' && tempS[i] <= 'Z')
			tempS[i] = tempS[i] - 'A' + 'a';
	return tempS;
}

