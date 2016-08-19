#include <iostream>
#include <string>
#include <string.h>
#include <dlfcn.h>
#include "callso4go.h"

using namespace std;

char* CallSo4Go(char* pfuncname, char* pinput, char* poutput){
	//absolute path of .so file
	const char *MYLIB_PATH="./libhw.so";

	//load the .so
	void *handle = dlopen(MYLIB_PATH, RTLD_NOW);

	//search the needed function
	typedef void (*FN_AppendHostname)(std::string const &input, std::string &output);
	FN_AppendHostname fn = (FN_AppendHostname)dlsym(handle, pfuncname);
	char *error = NULL;
	if((error = dlerror()) != NULL){
		cerr << "Symbol " << pfuncname << " not found" << error << endl;
		dlclose(handle);
	}

	string input = pinput;
	string output = poutput;
	
	//call the function
	fn(input, output);

	//convert type from string to char*
//	char * result = new char [output.length()+1];
//	strcat(result, output);
//	const char* conpresult = output.c_str();
//	char presult[100];
//	strcpy(presult, conpresult);
	char *presult = &output[0];	

//	cout << output << endl;	

	dlclose(handle);
	
	return presult;
}


/*
int main(){
	char pfuncname[] = "AppendHostname";
	char pinput[] = "Hello, I'm Caoxinjie";
	char *poutput = new char(100);
	char *presult = new char(100);
	presult = CallSo4Go(pfuncname, pinput, poutput);
	cout << presult << endl;
	return 0;
}
*/
