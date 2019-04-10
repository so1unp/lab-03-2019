CC=gcc
BIN=./bin
CFLAGS=-Wall -g -pthread -lm

PROG=proc thread threads forkvsthread 

LIST=$(addprefix $(BIN)/, $(PROG))

.PHONY: all
all: $(LIST)

$(BIN)/%: %.c
	$(CC) -o $@ $< $(CFLAGS)

%: %.c
	$(CC) -o $(BIN)/$@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(BIN)/proc $(BIN)/thread $(BIN)/threads $(BIN)/forkvsthread
