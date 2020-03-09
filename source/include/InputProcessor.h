
#ifndef MATCAL_INPUT_PROCESSING_H
#define MATCAL_INPUT_PROCESSING_H

#include<iostream>
#include<string>

using namespace std;

class Input {
private:
	string temp_help;
	string temp_exit;
	string temp_mat;
	string temp_print;
	string temp_inv;
	string temp_swapr;
	string temp_swapc;
public:
	string inputS;

	Input();

	bool cmpPre(string tempS, string cmpS);

	int inputAnalyse(string inputS);

};

extern Input input;

extern string toLower(string tempS);

#endif


