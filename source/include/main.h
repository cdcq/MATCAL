
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
};

extern Main mainClass;


int main();



