package main

import (
	"code.google.com/p/go.net/websocket"
)

type Conn struct {
	Ws *websocket.Conn
}

func NewConn() *Conn {
	return new(Conn)
}

func (this *Conn) Connect() error {
	if this.Ws != nil {
		return nil
	}
	ws, err := websocket.Dial("ws://evolver.danoolive.com:6969/api/cmd", "", "http://evolver.danoolive.com:6969")
	if err != nil {
		return err
	}
	this.Ws = ws
	return nil
}
