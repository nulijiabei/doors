package main

/*
	extern void init();
	extern int start();
	extern void input(void *, int);
	extern void * output();
*/
// #include <stdio.h>
// #include <stdlib.h>
// #cgo LDFLAGS: -L./ -ldoors
import "C"
import "unsafe"
import (
	// "bufio"
	// "code.google.com/p/go.net/websocket"
	"fmt"
	// "log"
	// "time"
)

// 记录
var history string

// 主
func main() {
	C.init()
	C.start()
}

//export input
func input(_content unsafe.Pointer, _size C.int) {
	command := string(C.GoBytes(_content, _size))
	content := fmt.Sprintf("$ %s", command)
	history = content + "\n" + history + "\n"
}

//export output
func output() unsafe.Pointer {
	return unsafe.Pointer(C.CString(history))
}
