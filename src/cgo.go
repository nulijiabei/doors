package main

/*
	extern void init();
	extern int start();
	extern void * request(void *, int);
*/
// #include <stdio.h>
// #include <stdlib.h>
// #cgo LDFLAGS: -L./ -ldoors
import "C"
import "unsafe"

func main() {
	C.init()
	C.start()
}

//export request
func request(_content unsafe.Pointer, _size C.int) unsafe.Pointer {
	content := unsafe.Pointer(C.CString(string(C.GoBytes(_content, _size))))
	return unsafe.Pointer(content)
}
