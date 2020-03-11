
#ifndef MATCAL_INPUT_PROCESSING_H
#define MATCAL_INPUT_PROCESSING_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Input {
public:
	vector<string> tempStr;

	Input();

	bool cmpPre(string tempS, string cmpS);

	int inputAnalyse(string inputS);

};

extern Input input;

extern string toLower(string tempS);

#endif


