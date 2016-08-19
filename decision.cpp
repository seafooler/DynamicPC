#include <iostream>
#include <string>
#include "decision.h"
#include "callso.h"
#include "callRemote.h"

using namespace std;

void CallFunc(std::string funcname, std::string const &input, std::string &output){
	bool local = false; //true represents locally, false represents remotely
	
	if(local){
		CallSo(funcname, input, output);
	}
	else{
		CallRemote(funcname, input, output);
	}
}


