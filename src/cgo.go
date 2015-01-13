package main

/*
	extern void init();
	extern int start();
	extern void input(void *, int);
	extern void * output();
*/
// #include <stdio.h>
// #include <stdlib.h>
// #cgo LDFLAGS: -L./ -ldoors -framework QtGui
import "C"
import "unsafe"
import (
	"bufio"
	"fmt"
	z "github.com/nutzam/zgo"
	"io"
	"log"
	"time"
)

// 连接
var conn *Conn

// 记录
var history string

// 主
func main() {
	conn = NewConn()
	go read()
	C.init()
	C.start()
}

//export input
func input(_content unsafe.Pointer, _size C.int) {
	command := string(C.GoBytes(_content, _size))
	if z.Trim(command) == "clear" {
		history = z.GetTime()
	} else {
		content := fmt.Sprintf("$ %s\n", command)
		history = fmt.Sprintf("%s\n%s\n", content, history)
		write(command)
	}
}

//export output
func output() unsafe.Pointer {
	return unsafe.Pointer(C.CString(history))
}

func read() {

	for {

		if err := conn.Connect(); err != nil {
			log.Println(err)
			time.Sleep(1 * time.Second)
			continue
		}

		r := bufio.NewReader(conn.Ws)

		for {

			data, err := r.ReadBytes('\n')
			if err != nil {
				log.Println(err)
				break
			}

			history = fmt.Sprintf("%s\n%s\n", string(data), history)

		}

	}

}

func write(_command string) error {

	if err := conn.Connect(); err != nil {
		return err
	}

	if _, err := io.WriteString(conn.Ws, _command+"\n"); err != nil {
		return err
	}

	return nil

}
