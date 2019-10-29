INCDIR=./include
LIBDIR=./lib
OBJDIR=./obj

CC=gcc
CFLAGS=-Wall -I$(INCDIR)

LIBS=-lcurl

_DEPS=https_handler.h tradebot_common.h
DEPS=$(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ=tradebot.o https_handler.o
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
