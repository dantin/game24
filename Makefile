CC=gcc
CFLAGS=

EXE=game24

OBJS=main.o game24.o

.PHONY: all clean $(EXE)

all: $(EXE)

$(EXE): $(OBJS)
	${CC} -o $(EXE) $(OBJS)

game24.o: game24.h
main.o: game24.h

clean:
	-rm -f ${EXE} $(OBJS) *~
