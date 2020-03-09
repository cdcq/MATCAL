
#include"../include/StringProcessor.h"


Fraction StrProc::getFra(string Str, unsigned int& pos, int minusFlag) {
	int temNum[2] = { 0, 1 };
	int denFlag = 0;
	for (; pos < Str.length(); pos++) {
		if (Str[pos] == '/') {
			denFlag = 1;
			temNum[1] = 0;
		}
		else if (Str[pos] < '0' || Str[pos] >'9') {
			pos = -1;
			return fra_0;
		}
		else {
			temNum[denFlag] = temNum[denFlag] * 10 + Str[pos] - '0';
			if (pos + 1 == Str.length() || ((Str[pos + 1] < '0' || Str[pos + 1] > '9') && Str[pos + 1] != '/')) {
				if (temNum[1] == 0) {
					pos = -2;
					return fra_0;
				}
				pos++;
				Fraction getedNum(temNum[0] * minusFlag, temNum[1]);
				return getedNum;
			}
		}
	}
	pos = -1;
	return fra_0;
}
int StrProc::getInt(string Str, unsigned int& pos, int minuFlag) {
	int temNum = 0;
	for (; pos < Str.length(); pos++) {
		if (Str[pos] == ' ') {
			continue;
		}
		else if (!isdigit(Str[pos])) {
			pos = -1;
			return 0;
		}
		else {
			temNum = temNum * 10 + Str[pos] - '0';
			if (pos + 1 == Str.length() || !isdigit(Str[pos + 1])) {
				pos++;
				return temNum;
			}
		}
	}
	pos = -1;
	return 0;
}
