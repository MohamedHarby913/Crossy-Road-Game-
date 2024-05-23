#include <stdio.h>
#include <stdlib.h>
#include "MapCreation.h"
#include "MapPrinting.h"
#include "CarMovement.h"
#include "Macros.h"
#include "GameChecking.h"
#include "terminal.h"
#include "LinkedList.h"

int main(int argc, char* argv[]) {
    /* This is the initialization of all the variables that will be used throughout the game */
    int i,j, x, y;
    int *rows_ptr, *columns_ptr;
    int executionFalied;
    char character; 
    char** map;
    char* input;
    int Goal [2];
    int gameFailed = FALSE;
    FILE* f;
    LinkedList* PlayerList;
    LinkedList* CarList;
    

        input = (char *)malloc(sizeof(char));
        rows_ptr = (int *)malloc(sizeof(int));
        columns_ptr = (int *)malloc(sizeof(int));
        PlayerList = (LinkedList*)malloc(sizeof(LinkedList));
        CarList = (LinkedList*)malloc(sizeof(LinkedList));

        if (rows_ptr == NULL || columns_ptr == NULL || input == NULL || PlayerList == NULL || CarList == NULL) 
        {
            printf("Memory allocation failed.\n");
            gameFailed = TRUE;
        }
        else{
        
            f = fopen(argv[1],"r");
            if(f == NULL) {
              printf("Error: could not open the file\n");
              gameFailed = TRUE;
              fclose(f);
            }
            /* This will read the file and get the map size */
            else {
              fscanf(f,"%d %d", rows_ptr, columns_ptr);
              if(ferror(f)) {
                perror("Error reading from the file \n");
                gameFailed = TRUE;
                fclose(f);
              }
              /* The upcoming block of code make sure that all the initialization of the memory in heap is done 
            correctly, otherwise it will free up the memory and terminate the game*/
              else{ 
                *rows_ptr = *rows_ptr + 2;
                *columns_ptr = *columns_ptr + 2;
                fclose(f);
                PlayerList->head = NULL;
                CarList->head = NULL;

                map = (char** )malloc(*rows_ptr * sizeof(char* ));


                if (map == NULL) {
                    printf("Memory allocation failed.\n");
                    free(rows_ptr);
                    rows_ptr = NULL;
                    free(columns_ptr);
                    columns_ptr = NULL;
                    free(input);
                    input = NULL;
                    freeLinkedList(PlayerList);
                    freeLinkedList(CarList);
                    gameFailed = TRUE;
                    
                }
                else{
                    for (i = 0; i < *rows_ptr; i++) {
                        if(gameFailed == FALSE){
                            map[i] = (char* )malloc(*columns_ptr * sizeof(char));
                            if (map[i] == NULL) {
                                printf("Memory allocation failed.\n");
                                for (j = 0; j < i; j++) {
                                    free(map[j]);
                                    map[j] = NULL;
                                }
                                free(map);
                                map = NULL;
                                free(rows_ptr);
                                rows_ptr = NULL;
                                free(columns_ptr);
                                columns_ptr = NULL;
                                free(input);
                                input = NULL;
                                freeLinkedList(PlayerList);
                                freeLinkedList(CarList);
                                gameFailed = TRUE;
                            }
                            else{
                                gameFailed = FALSE;
                            }
                        }
                    }
                }
           }
        }
    }
        



    

        if ( gameFailed == FALSE){
            mapCreation(map, rows_ptr, columns_ptr, argv, PlayerList, CarList, Goal);
	    system("clear");
	    mapPrinting(map, rows_ptr, columns_ptr);
        }
        else{
            executionFalied = TRUE;
        }

        while(gameFailed == FALSE && PlayerList->head != NULL){
            printf("Press w to move up\n");
            printf("Press s to move down\n");
            printf("Press a to move left\n");
            printf("Press d to move right\n");
            printf("Press u to undo\n");
            
            /* This takes the input of the user and make sure it is either w, a, s, d  or u */
            do{ 
                disableBuffer();
                scanf(" %c", input);
                enableBuffer();
            }while(*input != 'w' && *input != 'a' && *input != 's' && *input != 'd' && *input != 'u' );
            
            /* This upcoming if-else statement overwrites the player with a '.' or a ' ', this is done 
                because otherwise if the one car is directly beside the player, this might create an error 
                and one overwrite the other, so I will erase P from the map and after the car has moved 
                I will the put P in the new position*/
                
	        map[*((int*)PlayerList->head->x)][*((int*)PlayerList->head->y)] = *((char*)PlayerList->head->symbol);
            /* I tried putting this switch statement in other function in another file, but I found out that this will 
                create some redundancy and coupling, and the function would take too many parameters,
                so I just kept it in main*/
            switch (*input) {
            case 'w':
            if (PlayerList->head->x != NULL && PlayerList->head->y != NULL) {
              if(map[*((int*)PlayerList->head->x) - 1][*((int*)PlayerList->head->y)] != '*') {
                  x = *((int*)PlayerList->head->x) - 1;
                  y = *((int*)PlayerList->head->y);
                  if(map[*((int*)PlayerList->head->x) - 1][*((int*)PlayerList->head->y)] == ' '){
                  character = ' ';
                  }else 
                  {
                  character = '.';
                  }
                  insertFirst(PlayerList, &x, &y, &character);
                  carMovement(map, CarList);
              }
              }
              break;
            case 's':
            if (PlayerList->head->x != NULL && PlayerList->head->y != NULL) {
		if(map[*((int*)PlayerList->head->x) + 1][*((int*)PlayerList->head->y)] != '*') {
                  x = *((int*)PlayerList->head->x) + 1;
                  y = *((int*)PlayerList->head->y);
                  if(map[*((int*)PlayerList->head->x) + 1][*((int*)PlayerList->head->y)] == ' '){
                  character = ' ';
                  }else 
                  {
                  character = '.';
                  }
                  insertFirst(PlayerList, &x, &y, &character);
                   carMovement(map, CarList);
              }
              }
                break;
            case 'a':
            if (PlayerList->head->x != NULL && PlayerList->head->y != NULL) {
                if(map[*((int*)PlayerList->head->x) ][*((int*)PlayerList->head->y) -1 ] != '*') {
                  x = *((int*)PlayerList->head->x) ;
                  y = *((int*)PlayerList->head->y) -1 ;
                  if(map[*((int*)PlayerList->head->x)][*((int*)PlayerList->head->y) -1 ] == ' '){
                  character = ' ';
                  }else 
                  {
                  character = '.';
                  }
                  insertFirst(PlayerList, &x, &y, &character);
                   carMovement(map, CarList);
              }
              }
                break;
            case 'd':
            if (PlayerList->head->x != NULL && PlayerList->head->y != NULL) {
                if(map[*((int*)PlayerList->head->x) ][*((int*)PlayerList->head->y) + 1 ] != '*') {
                  x = *((int*)PlayerList->head->x) ;
                  y = *((int*)PlayerList->head->y) + 1 ;
                  if(map[*((int*)PlayerList->head->x)][*((int*)PlayerList->head->y) + 1 ] == ' '){
                  character = ' ';
                  }else 
                  {
                  character = '.';
                  }
                  insertFirst(PlayerList, &x, &y, &character);
                   carMovement(map, CarList);
                }
              }
              break;
        /* for the undo, I will delete the first node of the list and read the new first node, and assign the new positions */
              case 'u':
                if (listLength(PlayerList->head) > 1){
                  map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
                  deleteFirst(CarList);
                  map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = *((char*)CarList->head->symbol);
                  deleteFirst(PlayerList);
                }
                break;
                
            }
	    map[*((int*)PlayerList->head->x)][*((int*)PlayerList->head->y)] = 'P';
		
	    system("tput cup 0 0");
            mapPrinting(map, rows_ptr, columns_ptr);

            gameFailed = checkCondition(map, rows_ptr, columns_ptr, Goal);
        }
        /* This upcoming code is used for freeing the heap memory */
        for (i = 0; i < *rows_ptr; i++) {
            free(map[i]);
            map[i] = NULL;
        }
        freeLinkedList(PlayerList);
        freeLinkedList(CarList);
        free(map);
        map = NULL;
        free(rows_ptr);
        rows_ptr = NULL;
        free(columns_ptr);
        columns_ptr = NULL;
        free(input);
        input = NULL;
        executionFalied = FALSE; 
    
    
  return executionFalied;  
}
