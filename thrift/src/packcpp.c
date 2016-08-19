#include "packcpp.h"
#include <dlfcn.h>

char* callcallso4go(char* pfuncname, char* pinput, char *poutput){
	void *handle;
	typedef char* (*FPTR) (char*, char*, char*);
	
	handle = dlopen("./libcallso4go.so", 1);
	FPTR fptr = (FPTR)dlsym(handle, "CallSo4Go")	;
	
	return fptr(pfuncname, pinput, poutput);
}
