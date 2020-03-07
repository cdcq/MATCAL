
#ifndef MATCAL_INPUT_PROCESSING_H
#define MATCAL_INPUT_PROCESSING_H

#include<iostream>
#include<string>

using namespace std;

class Input{
private:
	string temp_help;
	string temp_exit;
	string temp_mat;
public:
	string inputS;

	Input();

	bool cmpPre(string tempS, string cmpS);

	int inputAnalyse(string inputS);

}input;

Input::Input(){
	temp_help = "help";
	temp_exit = "exit";
	temp_mat = "mat ";
}

bool Input::cmpPre(string tempS, string cmpS){
	if(tempS.length() < cmpS.length()){
		return false;
	}
	for(unsigned int i=0 ; i<cmpS.length() ; i++){
		if(tempS[i] != cmpS[i]){
			return false;
		}
	}
	return true;
}

int Input::inputAnalyse(string inputS){
	if(inputS == temp_exit){
		return 0;
	}
	else if(inputS == temp_help){
		return 1;
	}
	else if(cmpPre(inputS, temp_mat)){
		return 2;
	}
	
	return -1;
}

string toLower(string tempS){
	for(unsigned int i=0 ; i<tempS.length() ; i++)
		if(tempS[i]>='A' && tempS[i]<='Z')
			tempS[i] = tempS[i] - 'A' + 'a';
	return tempS;
}

#endif


