#include <iostream>
#include <string>
#include "hw.h"

#include <unistd.h>

using namespace std;

void AppendHostname(std::string const &input , std::string &output){
	char hname[128];
	struct hostent *hent;

	gethostname(hname, sizeof(hname));

	output = input + "	"+hname; 
}

/*
int main(){
	string input="hello, I'm seafooler";
	string output;
	AppendHostname(input, output);
	cout << output << endl;
	return 0;
}
*/
