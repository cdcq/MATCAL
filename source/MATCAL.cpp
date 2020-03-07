#include<iostream>
#include<cstdio>
#include<string>

#include "Matrix.h"

using namespace std;

string temp_help = "help";
string temp_exit = "exit";

int inputInstruct(string inputS){
	if(inputS == temp_help)
		return 0;
	if(inputS == temp_exit)
		return 1;
	
	return -1;
}

bool work(){
	printf(">> ");

	string inputS;
	cin>>inputS;

	int inputInfo = inputInstruct(inputS);

	if(inputInfo == 0){
		printf("°ïÖúĞÅÏ¢£º\n");
	}
	else if(inputInfo == 1){
		return 0;
	}

	return 1;
}

int main(){
	while(work());
	return 0;
}


