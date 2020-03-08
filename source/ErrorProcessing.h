
#ifndef _ERROR_PROCESSING_H
#define _ERROR_PROCESSING_H

#include<cstdio>

class Error{
public:

	void throwError(int errorInfo);
}error;

void Error::throwError(int errorInfo){
	printf("Error: ");
	if(errorInfo == -1){
		printf("无法处理输入，请检查指令格式\n");
		printf("键入help来获取帮助\n");
	}

	if(errorInfo == -201){
		printf("矩阵名已存在\n");
	}
	if(errorInfo == -202){
		printf("矩阵元素包含非法字符\n");
	}
	if(errorInfo == -203){
		printf("矩阵列数不一致\n");
	}

	if(errorInfo == 0){
		printf("不能除0！\n");
	}
}

#endif


