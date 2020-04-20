INCDIR=./include
LIBDIR=./lib
OBJDIR_TB=./obj_tb
OBJDIR_SB=./obj_sb

CC=gcc
CFLAGS=-Wall -I$(INCDIR)

LIBS=-lcurl -lm

_DEPS=https_handler.h tradebot_common.h json.h iex_api.h analyzer.h portfolio.h
DEPS=$(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ=tradebot.o https_handler.o json.o iex_api.o analyzer.o portfolio.o
OBJ_TB=$(patsubst %, $(OBJDIR_TB)/%,$(_OBJ))
OBJ_SB=$(patsubst %, $(OBJDIR_SB)/%,$(_OBJ))

$(OBJDIR_TB)/%.o: %.c $(DEPS)
	mkdir -p $(OBJDIR_TB)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR_SB)/%.o: %.c $(DEPS)
	mkdir -p $(OBJDIR_SB)
	$(CC) -c -o $@ $< $(CFLAGS)

tradebot: $(OBJ_TB)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	
sandbox : CFLAGS+=-D IEX_SANDBOX_MODE	
	
sandbox: $(OBJ_SB)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

all: tradebot
.PHONY: all

.PHONY: clean

clean:
	rm -rf $(OBJDIR_TB) $(OBJDIR_SB) tradebot sandbox
