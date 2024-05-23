#include <stdio.h>
#include "MapCreation.h"
#include "LinkedList.h"
/*****************************************
Name: mapCreation
Import: char** map, int* rows_ptr, int* columns_ptr, char* argv[], LinkedList* PlayerList,  LinkedList* CarList, int Goal[]

Export: None
Purpose: This function's role is to assign values in the 2D array which is the map, it reads the file and based on the data in the file, it assigns the position of everything.
******************************************/
void mapCreation(char** map, int* rows_ptr, int* columns_ptr, char* argv[], LinkedList* PlayerList,  LinkedList* CarList, int Goal[]){
    int i, j, ch, x , y;
    char character;
    FILE* f;
    f = fopen(argv[1],"r");
    if(f == NULL) {
      perror("Error opening in opening file");
    }
    else{ 
      fscanf(f,"%d %d", &ch , &ch);
      fscanf(f,"%d", &ch);
      if(ferror(f)) {
        perror("Error reading from the file\n");
      }
      for(i = 0; i< *rows_ptr;i++){
          for(j= 0; j< *columns_ptr ;j++){
              if (i == 0 || i == *rows_ptr-1){
                  map[i][j] = '*';
              }
              else if (j == 0 || j == *columns_ptr-1){
                  map[i][j] = '*';
              }
          }
      }
      for(i = 1; i< *rows_ptr -1 ;i++){
        for(j= 1; j< *columns_ptr -1 ;j++){
              if (ch == 0) {
                  map[i][j] = ' ';
              }
              else if (ch == 1){
                  map[i][j] = '.';
              }
              else if (ch == 3){
                  map[i][j] = 'P';
                  x = i;
                  y = j;
                  character = ' ';
                  insertFirst(PlayerList, (&x), (&y), (&character));
                  
              }
              else if (ch == 4){
                  map[i][j] = 'G';
                  Goal[0] = i;
                  Goal[1] = j;
              }
              else if ( ch == 2 ){
                  map[i][j] = '>';
                  x = i;
                  y = j;
                  character = '>';
                  insertFirst(CarList, (&x), (&y), (&character));
              }
           fscanf(f,"%d", &ch);   
          }
        }
    }
   fclose(f);
}
