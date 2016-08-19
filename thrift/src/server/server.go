package main

/*
#include "packcpp.h"
#include <stdlib.h>
#cgo LDFLAGS: -L./ -lpackcpp -lcallso4go -ldl
*/
import "C"

import (
	"com/seafooler/project"
	"fmt"
	"git.apache.org/thrift.git/lib/go/thrift"
	"os"
	"unsafe"
)

const (
	NetworkAddr = "127.0.0.1:9090"
)

type callThrift struct {
}

func (this *callThrift) CallFunc(funcname string, input string) (r string, err error){
	fmt.Println("-->from client Call: funcname:", funcname)
	fmt.Println("-->from client Call: input:", input)

	cfuncname := C.CString(funcname)
        defer C.free(unsafe.Pointer(cfuncname))
        cinput := C.CString(input)
        defer C.free(unsafe.Pointer(cinput))
        var output string
        coutput := C.CString(output)
        defer C.free(unsafe.Pointer(coutput))
        fmt.Println("Before CallCallSo4GO!")
        cresult := C.callcallso4go(cfuncname, cinput, coutput)
        fmt.Println("CallCallSo4GO is finished!")
        r = C.GoString(cresult)
	
	r += "\nvia thrift"
	
	fmt.Println("To Client-->: result:", r)
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

