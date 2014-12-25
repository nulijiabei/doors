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
import "fmt"

func main() {
	C.init()
	C.start()
}

//export request
func request(_content unsafe.Pointer, _size C.int) unsafe.Pointer {
	fmt.Println(string(C.GoBytes(_content, _size)))
	content := unsafe.Pointer(C.CString("你好, Golang"))
	defer func() {
		C.free(content)
	}()
	return unsafe.Pointer(content)

}
