
#ifndef _ERROR_PROCESSING_H
#define _ERROR_PROCESSING_H

#include<cstdio>

class Error {
public:

	void throwError(int errorInfo);
};

extern Error error;

#endif


