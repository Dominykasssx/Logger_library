CFLAGS:=-Wall
LIB:=libLogger.so
LIB_SRCS := logger.c
PREFIX := /usr
LFLAGS:=-lsqlite3

.PHONY: clean all install uninstall

all: $(LIB)	

$(LIB):  $(LIB_SRCS)
	$(CC) $(CFLAGS) -fpic -shared -o $@ $^ $(LFLAGS)

install: $(LIB)
	install -d $(PREFIX)/lib $(PREFIX)/include
	install -m 644 $(LIB) $(PREFIX)/lib
	install -m 644 logger.h $(PREFIX)/include
	
uninstall:
	$(RM) $(PREFIX)/lib/$(LIB)
	$(RM) $(PREFIX)/include/logger.h
clean:
	$(RM) $(LIB)