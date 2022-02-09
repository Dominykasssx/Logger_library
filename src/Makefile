BIN:= writeLog1 writeLog2 writeLog3
BIN2:=readLog
OBJS:= writeLog1.o
SRC:= readLog1.c
CFLAGS:=-Wall
CPPFLAGS := -I$(shell pwd)/../lib
LDFLAGS := -L$(shell pwd)/../lib -lLogger
PREFIX := /usr

.PHONY: clean all install uninstall
all: $(BIN) $(BIN2)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(CPPFLAGS) $(LDFLAGS)

$(BIN2): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(CPPFLAGS) $(LDFLAGS)

install: 
	install -d $(PREFIX)/bin
	install -m 555 $(BIN2) $(PREFIX)/bin
	install -m 555 $(BIN) $(PREFIX)/bin

uninstall:
	$(RM) $(PREFIX)/bin/$(BIN2)
	$(RM) $(PREFIX)/bin/$(BIN)

	
clean:
	$(RM) $(BIN) $(OBJS) $(BIN2)