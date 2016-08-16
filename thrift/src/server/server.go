package main

import (
	"com/seafooler/project"
	"fmt"
	"git.apache.org/thrift.git/lib/go/thrift"
	"os"
)

const (
	NetworkAddr = "127.0.0.1:9090"
)

type callThrift struct {
}

func (this *callThrift) CallFunc(funcname string, input string) (r string, err error){
	fmt.Println("-->from client Call: funcname:", funcname)
	fmt.Println("-->from client Call: input:", input)
	r = input + "	Hello, haodagou"
	return
}

func main() {
	transportFactory := thrift.NewTBufferedTransportFactory(2048)
        protocolFactory := thrift.NewTBinaryProtocolFactoryDefault()
        serverTransport, err := thrift.NewTServerSocket(NetworkAddr)
        if err != nil {
                fmt.Println("Error!", err)
                os.Exit(1)
        }

	handler := &callThrift{}
	processor := project.NewCallThriftProcessor(handler)

	server := thrift.NewTSimpleServer4(processor, serverTransport, transportFactory, protocolFactory)
        fmt.Println("thrift server in", NetworkAddr)
        server.Serve()
}

