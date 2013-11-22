.PHONY:	clean default all

MAKE	:= make
GCC 	:= gcc
CFLAGS	:= -std=c99
LFLAGS 	:= -lm 
TAR		:= tar -zcvf
RM		:= rm -rf
CD		:= cd
MV		:= mv

all:
	$(MAKE) integrations

integrations: euler.c integrations.c integrations.h
	$(GCC) $(CFLAGS) euler.c integrations.c integrations.h -o integrations $(LFLAGS)

clean:
	$(RM) integrations *~

tarball:
	$(MAKE) clean
	$(CD) .. && $(TAR) ass3.tar.gz ass3

default:
	all
