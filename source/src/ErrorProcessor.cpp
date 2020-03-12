
#include"../include/ErrorProcessor.h"

Error error;

void Error::throwError(int errorInfo) {
	printf("Error: ");
	if (errorInfo == -1) {
		printf("无法处理输入，请检查指令格式\n");
		printf("键入help来获取帮助\n");
	}

	if (errorInfo == -200) {
		printf("矩阵名不存在\n");
	}
	if (errorInfo == -201) {
		printf("矩阵名已存在\n");
	}
	if (errorInfo == -202) {
		printf("矩阵元素包含非法字符\n");
	}
	if (errorInfo == -203) {
		printf("矩阵列数不一致\n");
	}
	if (errorInfo == -204) {
		printf("矩阵无法相乘\n");
	}
	if (errorInfo == -205) {
		printf("矩阵无法相加/相减\n");
	}
	if (errorInfo == -206) {
		printf("矩阵不是方阵\n");
	}
	if (errorInfo == -207) {
		printf("矩阵不可逆\n");
	}

	if (errorInfo == -3) {
		printf("参数不合法\n");
	}

	if (errorInfo == 0) {
		printf("不能除0！\n");
	}
}

