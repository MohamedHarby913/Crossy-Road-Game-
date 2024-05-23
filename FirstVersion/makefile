CC = gcc 
CFLAGS = -Wall -pedantic -ansi -g
OBJ = main.o random.o terminal.o MapCreation.o MapPrinting.o CarMovement.o GameChecking.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c random.h terminal.h MapCreation.h MapPrinting.h CarMovement.h GameChecking.h Macros.h
	$(CC) -c main.c $(CFLAGS)

random.o : random.c random.h
	$(CC) -c random.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

MapCreation.o: MapCreation.c MapCreation.h random.h
	$(CC) -c MapCreation.c $(CFLAGS)

MapPrinting.o: MapPrinting.c MapPrinting.h
	$(CC) -c MapPrinting.c $(CFLAGS)

CarMovement.o: CarMovement.c CarMovement.h Macros.h
	$(CC) -c CarMovement.c $(CFLAGS)

GameChecking.o: GameChecking.c GameChecking.h Macros.h
	$(CC) -c GameChecking.c $(CFLAGS)

clean: 	
	rm -f $(EXEC) $(OBJ)

