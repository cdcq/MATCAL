
#ifndef MATCAL_STRING_PROCESSING_H
#define MATCAL_STRING_PROCESSING_H

#include"Fraction.h"
#include<string>

using namespace std;

class StrProc {
public:

	Fraction getFra(string Str, unsigned int &pos);
	int getInt(string Str, unsigned int& pos);
	string getStr(string Str, unsigned int& pos);
};

#endif

