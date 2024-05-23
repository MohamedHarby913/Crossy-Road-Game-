#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "MapCreation.h"
#include "MapPrinting.h"
#include "CarMovement.h"
#include "Macros.h"
#include "GameChecking.h"
#include "terminal.h"


int main(int argc, char* argv[]) {
    /* This is the initialization of all the variables that will be used throughout the game */
    int i,j;
    int *rows_ptr, *columns_ptr;
    int executionFalied;
    char** map;
    char* input;
    int* numOfCars;
    int gameFailed = FALSE;
    int playerArray[2] = {1,1};
    initRandom();
    
    /*  This checks if the user giving the right amount of arguments*/
    if (argc != 3) {
        printf("Usage: %s <rows> <columns>\n", argv[0]);
        executionFalied =  TRUE;
    }
    /* This checks that the number of rows are odd */
    else if ( (atoi(argv[1]) % 2 ) == 0 ){
        printf("The number of rows has to be an odd number\n");
        executionFalied =  TRUE;   
    }
    /* This checks that the number of rows are 3 or more  */
    else if (atoi(argv[1]) < 3){
	    printf("The minimum number for rows are 3\n");
    }
    /* This checks that the number of columns are 5 or more  */
    else if (atoi(argv[2]) < 5){
	    printf("The minimum number for columns are 5\n");
    }
    else{

        input = (char *)malloc(sizeof(char));
        rows_ptr = (int *)malloc(sizeof(int));
        columns_ptr = (int *)malloc(sizeof(int));
	    numOfCars = (int *)malloc(sizeof(int));


        if (rows_ptr == NULL || columns_ptr == NULL || input == NULL || numOfCars == NULL) {
            printf("Memory allocation failed.\n");
            gameFailed = TRUE;
        }
        else{
        /* The upcoming block of code make sure that all the initialization of the memory in heap is done 
            correctly, otherwise it will free up the memory and terminate the game*/
            
            *rows_ptr = atoi(argv[1]) + 2;
            *columns_ptr = atoi(argv[2]) + 2;
            *numOfCars = (atoi(argv[1]) -1) / 2; 

            map = (char** )malloc(*rows_ptr * sizeof(char* ));


            if (map == NULL) {
                printf("Memory allocation failed.\n");
                free(rows_ptr);
                rows_ptr = NULL;
                free(columns_ptr);
                columns_ptr = NULL;
                free(input);
                input = NULL;
                free(numOfCars);
                numOfCars = NULL;
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
                            free(numOfCars);
                            numOfCars = NULL;
                            gameFailed = TRUE;
                        }
                        else{
                            gameFailed = FALSE;
                        }
                    }
                }
            }
        }
        
        if ( gameFailed == FALSE){
            mapCreation(map, rows_ptr, columns_ptr);
	    system("clear");
            mapPrinting(map, rows_ptr, columns_ptr);
        }
        else{
            executionFalied = TRUE;
        }

        while(gameFailed == FALSE){
            printf("Press w to move up\n");
            printf("Press s to move down\n");
            printf("Press a to move left\n");
            printf("Press d to move right\n");
            
            /* This takes the input of the user and make sure it is either w, a, s or d */
            do{ 
                disableBuffer();
                scanf(" %c", input);
                enableBuffer();
            }while(*input != 'w' && *input != 'a' && *input != 's' && *input != 'd' );
            
            /* This upcoming if-else statement overwrites the player with a '.' or a ' ', this is done 
                because otherwise if the one car is directly beside the player, this might create an error 
                and one overwrite the other, so I will erase P from the map and after all the cars have moved 
                I will the put P in the new position*/
                
	        if(map[playerArray[0]][playerArray[1] + 1] == ' ' ||map[playerArray[0]][playerArray[1] - 1] == ' '){
                	map[playerArray[0]][playerArray[1]] = ' ';
            	}
            	else{
                	map[playerArray[0]][playerArray[1]] = '.';
            	}
            /* I tried putting this switch statement in other function in another file, but I found out that this will 
                create some redundancy and coupling, and the function would take too many parameters,
                so I just kept it in main*/
            switch (*input) {
            case 'w':
		if(map[playerArray[0] - 1][playerArray[1]] !='*'){
                   playerArray[0] = playerArray[0] -1;
                   carMovement(map, rows_ptr, columns_ptr);
	   	}
                break;
            case 's':
		if(map[playerArray[0] +1][playerArray[1]] !='*'){
		   playerArray[0] = playerArray[0] + 1;
                   carMovement(map, rows_ptr, columns_ptr);
		}
                break;
            case 'a':
                if(map[playerArray[0]][playerArray[1] - 1 ] !='*'){
                    playerArray[1] = playerArray[1] - 1; 
                    carMovement(map, rows_ptr, columns_ptr);
		}
                break;
            case 'd':
                if(map[playerArray[0]][playerArray[1]+ 1] !='*'){
                    playerArray[1] = playerArray[1] + 1;
                    carMovement(map, rows_ptr, columns_ptr);
                break;
                }
            }
	    map[playerArray[0]][playerArray[1]] = 'P';
		
	    system("tput cup 0 0");
            mapPrinting(map, rows_ptr, columns_ptr);

            gameFailed = checkCondition(map, rows_ptr, columns_ptr, numOfCars);
        }
        /* This upcoming code is used for freeing the heap memory */
        for (i = 0; i < *rows_ptr; i++) {
            free(map[i]);
            map[i] = NULL;
        }
        free(map);
        map = NULL;
        free(rows_ptr);
        rows_ptr = NULL;
        free(columns_ptr);
        columns_ptr = NULL;
        free(input);
        input = NULL;
        free(numOfCars);
        numOfCars = NULL;
        executionFalied = FALSE; 
    }
    
  return executionFalied;  
}
