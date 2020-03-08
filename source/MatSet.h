
#ifndef MATCAL_MATH_SET_H
#define MATCAL_MATH_SET_H

#include"Matrix.h"
#include<map>
#include<string>

class MatSet{
public:
	map<string, Matrix> set;

	void matInput(string matName);

}matSet;

void MatSet::matInput(string matName){
	if(matSet.set.count(matName)){
		error.throwError( -201 );
		return ;
	}
	Matrix temMat;
	temMat.name = matName;

	string inputS;
	for(;;){
		getline(cin, inputS);
		if(inputS.length() == 0){
			break;
		}
		temMat.n++;
		int temCol = 0;
		int temNum[2] = {0, 1};
		int denFlag = 0;
		int minusFlag = 1;
		for(unsigned int i=0 ; i<inputS.length() ; i++){
			if(inputS[i] == ' '){
				continue;
			}
			else if(inputS[i] == '/'){
				denFlag = 1;
				temNum[1] = 0;
			}
			else if(inputS[i] == '-'){
				minusFlag = -1;
			}
			else if(inputS[i]<'0' || inputS[i] >'9'){
				error.throwError( -202 );
				return ;
			}
			else{
				temNum[denFlag] = temNum[denFlag]*10 + inputS[i] - '0';
				if(inputS[i+1]==' ' || i+1==inputS.length()){
					if(temNum[1] == 0){
						error.throwError( 0 );
						return ;
					}
					temCol++;
					Fraction inputNum(temNum[0]*minusFlag, temNum[1]);
					temMat.mat[temMat.n][temCol] = inputNum;
					temNum[0] = 0;
					temNum[1] = 1;
					denFlag = 0;
				}
			}
		}
		if(temMat.m == 0){
			temMat.m = temCol;
		}
		else if(temCol != temMat.m){
			error.throwError( -203 );
			return ;
		}
	}
	
	matSet.set[matName] = temMat;
}

#endif


