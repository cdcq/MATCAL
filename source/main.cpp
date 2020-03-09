
#include"ErrorProcessing.h"
#include"InputProcessing.h"
#include"LaunchInfo.h"
#include"MatSet.h"
#include"Matrix.h"
#include<fstream>
#include<map>
#include<string>

void init();

bool work();

int main(){
	init();

	while(work());
	return 0;
}

void init(){
	launchInfo.printInfo();
}

bool work(){
	printf(">> ");

	string inputS;
	getline(cin, inputS);
	if(inputS.length() == 0){
		return true;
	}

	inputS = toLower(inputS);
	if(matSet.set.count(inputS)){
		matSet.set[inputS].print();
		return true;
	}
	int inputInfo = input.inputAnalyse(inputS);

	if(inputInfo == 0){
		return false;
	}
	else if(inputInfo == 1){
	}
	else if(inputInfo == -1){
		error.throwError( -1 );
		return true;
	}
	else if(inputInfo == 2){
		inputS.erase(0, 4);
		string matName = inputS;
		matSet.matInput(matName);
		return true;
	}

	return true;
}

