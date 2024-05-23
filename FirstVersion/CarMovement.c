#include <stdio.h>
#include "CarMovement.h"
#include "Macros.h"

/*****************************************
Name: carMovement
Import: char** map, int* rows_ptr, int* columns_ptr
Export: None
Purpose: This function's role is to update the cars' positions every time the player has moved,
the cars move in their direction until they hit a wall and they change their direction
******************************************/
void  carMovement(char** map, int* rows_ptr, int* columns_ptr){
    
    int i,j;
    int carMoved;
    for (i = 2; i< *rows_ptr - 1; i = i+2){
        carMoved = FALSE;
        for(j = 1; j< *columns_ptr - 1;j++){           
            if(carMoved == FALSE){
                if(map[i][j] == '<'){
                    if(map[i][j-2] != '*'){
                        map[i][j-1] ='<';
                    }
                    else{
                        map[i][j-1] ='>';
                    }
                    map[i][j] ='.';
                    carMoved = TRUE;
                }
                else if(map[i][j] == '>'){
                    if(map[i][j+2] != '*'){
                        map[i][j+1] ='>';
                    }
                    else{
                        map[i][j+1] ='<';
                        }
                    map[i][j] ='.';
                    carMoved = TRUE;
                }
            }
        }
    }
}
