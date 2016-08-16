#include <iostream>
#include "hw.h"

using namespace std;

int main(){
	string input = "Hello, I'm Haodagou";
	string output;
	AppendHostname(input, output);
	cout << output <<endl;
	return 0;
}
