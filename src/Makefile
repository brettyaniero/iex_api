INCDIR=./include
LIBDIR=./lib
OBJDIR=./obj

CC=gcc
CFLAGS=-Wall -I$(INCDIR)

LIBS=-lcurl -lm

_DEPS=https_handler.h tradebot_common.h json.h iex_api.h
DEPS=$(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ=tradebot.o https_handler.o json.o iex_api.o
OBJ=$(patsubst %, $(OBJDIR)/%,$(_OBJ))

$(OBJDIR)/%.o: %.c $(DEPS)
	mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

tradebot: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

all: tradebot
.PHONY: all

.PHONY: clean

clean:
	rm -rf $(OBJDIR) tradebot
