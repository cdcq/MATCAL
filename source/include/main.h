
#include"ErrorProcessor.h"
#include"Fraction.h"
#include"InputProcessor.h"
#include"LaunchInfo.h"
#include"LexicalAnalyzer.h"
#include"Matrix.h"
#include"MatSet.h"
#include<map>
#include<string>


class Main {
private:
	LexicalAnalyzer lexAna;
	StrProc strProc;

public:

	void init();
	bool work();

	void execInput(string inputS, int inputInfo);
	void execPrint(string inputS, int inputInfo);
	void execSwap(string inputS, int inputInfo);
	void execOper(string inputS, int inputInfo);
	void execTurn(string inputS, int inputInfo);
	void execDet(string inputS, int inputInfo);
	void execInv(string inputS, int inputInfo);
	void execRank(string inputS, int inputInfo);
	void execTriu(string inputS, int inputInfo);
};

extern Main mainClass;


int main();



