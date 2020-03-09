
#ifndef MATCAL_MATH_SET_H
#define MATCAL_MATH_SET_H

#include"ErrorProcessor.h"
#include"Matrix.h"
#include"StringProcessor.h"
#include<iostream>
#include<map>
#include<string>

class MatSet {
private:
	StrProc strProc;
public:
	map<string, Matrix> set;

	void matInput(string matName);

};

extern MatSet matSet;



#endif


