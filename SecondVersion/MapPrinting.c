#include <stdio.h>
#include "MapPrinting.h"



/*****************************************
Name: mapPrinting
Import: char** map, int* rows_ptr, int* columns_ptr
Export: None
Purpose: This function's role is to print the 2D array which is the map using two for loops
******************************************/
void mapPrinting(char** map, int* rows_ptr, int* columns_ptr){
    int i, j;
    for(i= 0; i< *rows_ptr;i++){
        for(j= 0; j< *columns_ptr;j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
