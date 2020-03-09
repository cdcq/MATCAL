
#ifndef MATCAL_MATH_SET_H
#define MATCAL_MATH_SET_H

#include"ErrorProcessing.h"
#include"Matrix.h"
#include<iostream>
#include<map>
#include<string>

class MatSet {
public:
	map<string, Matrix> set;

	void matInput(string matName);

};

extern MatSet matSet;



#endif


