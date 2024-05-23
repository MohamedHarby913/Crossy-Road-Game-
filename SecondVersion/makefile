CC = gcc 
CFLAGS = -Wall -pedantic -ansi -g
OBJ = main.o terminal.o MapCreation.o MapPrinting.o CarMovement.o GameChecking.o LinkedList.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c terminal.h MapCreation.h MapPrinting.h CarMovement.h GameChecking.h Macros.h LinkedList.h
	$(CC) -c main.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

MapCreation.o: MapCreation.c MapCreation.h LinkedList.h
	$(CC) -c MapCreation.c $(CFLAGS)

MapPrinting.o: MapPrinting.c MapPrinting.h
	$(CC) -c MapPrinting.c $(CFLAGS)

CarMovement.o: CarMovement.c CarMovement.h Macros.h LinkedList.h
	$(CC) -c CarMovement.c $(CFLAGS)

GameChecking.o: GameChecking.c GameChecking.h Macros.h
	$(CC) -c GameChecking.c $(CFLAGS)

LinkedList.o: LinkedList.c LinkedList.h
	$(CC) -c LinkedList.c $(CFLAGS)

clean: 	
	rm -f $(EXEC) $(OBJ)

