#include <stdio.h>
#include "MapCreation.h"
#include "random.h"

/*****************************************
Name: mapCreation
Import: char** map, int* rows_ptr, int* columns_ptr
Export: None
Purpose: This function's role is to assign values in the 2D array which is the map, it first assign the roads and the 
borders then assign the cars randomly, and at the end the player's starting position and the goal's are assigned
******************************************/
void mapCreation(char** map, int* rows_ptr, int* columns_ptr){
    int i, j;
    for(i = 0; i< *rows_ptr;i++){
        for(j= 0; j< *columns_ptr;j++){
            if (i == 0 || i == *rows_ptr-1){
                map[i][j] = '*';
            }
            else if (j == 0 || j == *columns_ptr-1){
                map[i][j] = '*';
            }
            else if (( i % 2 ) != 0) {
                map[i][j] = ' ';
            }
            else{
                map[i][j] = '.';
            }
        }
    }
    
    /* Here I am using the random function twice once for the car's position and another time for the direction */
    for(i = 2; i< *rows_ptr - 1; i = i+2){
        int randNum = randomUCP(1,*columns_ptr - 2);
        if(randNum == 1){
            map[i][randNum] = '>';

        }
        else if(randNum == *columns_ptr - 2){
            map[i][randNum] = '<';
        }
        else if ( randomUCP(0,1) == 1){
            map[i][randNum] = '>';
        }
        else{
            map[i][randNum] = '<';
        }
    }
    
    map[1][1] = 'P';
    map[*rows_ptr - 2][*columns_ptr - 2] = 'G';

}
