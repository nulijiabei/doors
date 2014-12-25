package main

/*
	extern int start();
	extern int drv_appmain();
*/
// #cgo LDFLAGS: -L./ -ldemo
import "C"

func main() {
	C.start()
}

//export drv_appmain
func drv_appmain() C.int {
	return 100
}
