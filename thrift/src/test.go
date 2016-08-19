package main

/*
#include "packcpp.h"
#include <stdlib.h>
#cgo LDFLAGS: -L./ -lpackcpp -lcallso4go -ldl
*/
import "C"

import "fmt"
import "unsafe"

func main() {
	funcname := "AppendHostname"
	cfuncname := C.CString(funcname)
	input := "haohaoahaoahao woshiyizhidacaogou"
	cinput := C.CString(input)
	var output string
	coutput := C.CString(output)
		

	defer C.free(unsafe.Pointer(cfuncname))
	defer C.free(unsafe.Pointer(cinput))
	defer C.free(unsafe.Pointer(coutput))
	
	cresult := C.callcallso4go(cfuncname, cinput, coutput)
//	defer C.free(unsafe.Pointer(cresult))	
	
	fmt.Printf("Everything is OK!")	
	result :=C.GoString(cresult)
	fmt.Printf(result)
}
