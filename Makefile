CFLAGS = -Wextra -Wall

all: program.c game.o
	gcc $(CFLAGS) program.c game.o ui_service.o word_service.o -o main

goida: program.c game.o
	gcc $(CFLAGS) program.c game.o ui_service.o word_service.o -o main -DGOIDA

clean:
	rm *.o *.out *.exe main

game.o: game.c ui_service.o word_service.o
	gcc $(CFLAGS) -c game.c ui_service.o word_service.o

ui_service.o: ui_service.c 
	gcc $(CFLAGS) -c ui_service.c

word_service.o: word_service.c
	gcc $(CFLAGS) -c word_service.c