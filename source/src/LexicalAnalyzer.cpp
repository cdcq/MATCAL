
#include"../include/LexicalAnalyzer.h"

bool LexicalAnalyzer::RecPar(string Str, int parSet[], int parNum) {
	// parSet是参数列表，绝对值为0是空格，1是字符，2是数字。parNum是参数个数。
	// 值小于等于0表示终止状态，为正则不是。
	int point = 0;
	for (unsigned int pos = 0; pos < Str.length(); pos++) {
		if (parSet[point] == 0) {
			if (Str[pos] != ' ') {
				point++;
			}
		}
		else if (abs(parSet[point]) == 1) {
			if (Str[pos] == ' ') {
				point++;
			}
			else if (!islower(Str[pos])) {
				return false;
			}
		}
		else if (abs(parSet[point]) == 2) {
			if (Str[pos] == ' ') {
				point++;
			}
			else if (!isdigit(Str[pos])) {
				return false;
			}
		}
		if (point > parNum) {
			return false;
		}
	}
	return parSet[point] < 0;
}