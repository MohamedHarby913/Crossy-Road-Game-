#include <stdio.h>
#include "GameChecking.h"
#include "Macros.h"


/*****************************************
Name: checkCondition
Import: char** map, int* rows_ptr, int* columns_ptr, int* numOfCars
Export: (int) conditionMet
Purpose: This function's role is to check if the player has won or lost the game after every time the player 
has moved, it first checks if the player has lost by counting the number of cars, if the number of cars are less than
they are supposed to be then the player has lost, and then it checks if the player has won, by checking if the player is in the G's position.
******************************************/
int checkCondition(char** map, int* rows_ptr, int* columns_ptr, int* numOfCars){
    	int i,j;
    	int counter =0;
    	int conditionMet;
	for(i = 1; i < *rows_ptr -1 ;i++){
		for(j = 1; j< *columns_ptr - 1;j++){
			if(map[i][j] =='>' || map[i][j] == '<'){
				counter ++;
			}
		}
	}

	if(counter != *numOfCars){
		printf("\n\n\n\n\n");
		printf("You have lost the game\n");
        	conditionMet = TRUE;
	}
    	else if(map[*rows_ptr -2][*columns_ptr -2] == 'P'){
        	printf("\n\n\n\n\n");
        	printf("You have won the game\n");
        	conditionMet = TRUE;
    	}
    	else{
        	conditionMet = FALSE;
    }
    return conditionMet;
}
