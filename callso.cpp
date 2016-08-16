#include <iostream>
#include <string>
#include <dlfcn.h>
#include "callso.h"

using namespace std;

void CallSo(std::string funcname, std::string const &input, std::string &output){
	//convert string to char*, because dlsym can only accept char* as the argument
	const char *pfuncname = funcname.c_str();

	//absolute path of .so file
	const char *MYLIB_PATH="/home/seafooler/HKUST/thrift3/dynamic/libhw.so";

	//load the .so
	void *handle = dlopen(MYLIB_PATH, RTLD_NOW);

	//search the needed function
	typedef void (*FN_AppendHostname)(std::string const &input, std::string &output);
	FN_AppendHostname fn = (FN_AppendHostname)dlsym(handle, pfuncname);
	char *error = NULL;
	if((error = dlerror()) != NULL){
		cerr << "Symbol " << funcname << " not found" << error << endl;
		dlclose(handle);
	}

	//call the function
	fn(input, output);
	
//	cout << output << endl;	

	dlclose(handle);
}

/*
int main(){
	string funcname = "AppendHostname";
	string input = "Hello, I'm Caoxinjie";
	string output;
	CallFunc(funcname, input, output);
	return 0;
}
*/
