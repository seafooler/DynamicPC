#include "callThrift.h"  
#include <transport/TSocket.h>  
#include <transport/TBufferTransports.h>  
#include <protocol/TBinaryProtocol.h>  
#include <iostream>
#include <string>
#include <unistd.h>

using namespace apache::thrift;  
using namespace apache::thrift::protocol;  
using namespace apache::thrift::transport;  
  
using boost::shared_ptr;  
  
int main(int argc, char **argv) {  
        boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));  
        boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));  
        boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));  
  
        transport->open();  
	
	std::cout << "after transport->open()" << std::endl;
	com::seafooler::project::callThriftClient client(protocol);
	
	std::cout << "after client" << std::endl;
	
	/*
	void CallFunc(std::string& _return, const std::string& funcname, const std::string& input)	
	*/
	std::string funcname="Seafooler";	//funcname
	std::string input="haodagou is a pig";	//input
	std::string output;
	client.CallFunc(output, funcname, input);

	std::cout << "output: " << output << std::endl;        
	sleep(5);
	std::cout << "before transport->close()" << std::endl;
	
	transport->close();  
	return 0;
}  
