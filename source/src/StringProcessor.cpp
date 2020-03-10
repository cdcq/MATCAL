
#include"../include/StringProcessor.h"


Fraction StrProc::getFra(string Str, unsigned int& pos) {
	int temNum[2] = { 0, 1 };
	int denFlag = 0;
	for (; pos < Str.length() && Str[pos] == ' '; pos++);
	for (; pos < Str.length(); pos++) {
		if (Str[pos] == ' ') {
			break;
		}
		if (Str[pos] == '/') {
			denFlag = 1;
			temNum[1] = 0;
		}
		else if (!isdigit(Str[pos])) {
			pos = -1;
			return fra_0;
		}
		else {
			temNum[denFlag] = temNum[denFlag] * 10 + Str[pos] - '0';
		}
	}
	if (temNum[1] == 0) {
		pos = -2;
		return fra_0;
	}
	Fraction getedNum(temNum[0], temNum[1]);
	return getedNum;
}
int StrProc::getInt(string Str, unsigned int& pos) {
	int temNum = 0;
	for (; pos < Str.length() && Str[pos] == ' '; pos++);
	for (; pos < Str.length(); pos++) {
		if (Str[pos] == ' ') {
			break;
		}
		else if (!isdigit(Str[pos])) {
			pos = -1;
			return temNum;
		}
		else {
			temNum = temNum * 10 + Str[pos] - '0';
		}
	}
	return temNum;
}
string StrProc::getStr(string Str, unsigned int& pos) {
	string temStr = "";
	for (; pos < Str.length() && Str[pos] == ' '; pos++);
	for (; pos < Str.length(); pos++) {
		if (Str[pos] == ' ') {
			break;
		}
		else if (!islower(Str[pos])) {
			pos = -1;
			return temStr;
		}
		else {
			temStr.append(1, Str[pos]);
		}
	}
	return temStr;
}

