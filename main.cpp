#include <iostream>
#include "decision.h"

using namespace std;

int main(){
	string funcname = "AppendHostname";
	string input = "Hello, I'm Caoxinjie";
	string output;
	CallFunc(funcname, input, output);
 	cout << output << endl;
	return 0;
}
