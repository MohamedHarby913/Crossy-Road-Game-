#include <stdio.h>
#include "CarMovement.h"
#include "Macros.h"
#include "LinkedList.h"
/*****************************************
Name: carMovement
Import: char** map, LinkedList* CarList
Export: None
Purpose: This function's role is to update the car positions every time the player has moved,
the car move in their direction until they hit a wall and they change their direction
******************************************/
void  carMovement(char** map, LinkedList* CarList){
    
    int x, y;
    char character;
    if(*((char*)CarList->head->symbol) == '>'){
        if(map[*((int*)CarList->head->x)][*((int*)CarList->head->y) + 1] == '.'){
          map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
          x = *((int*)CarList->head->x);
          y = *((int*)CarList->head->y) + 1;
          character = '>';
          }
          else if(map[*((int*)CarList->head->x )- 1][*((int*)CarList->head->y)] == '.'){
            map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
            x = *((int*)CarList->head->x) -1 ;
            y = *((int*)CarList->head->y);
            character = '^';
            }
          else if (map[*((int*)CarList->head->x) + 1][*((int*)CarList->head->y)] == '.'){
            map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
            x = *((int*)CarList->head->x) + 1  ;
            y = *((int*)CarList->head->y);
            character = 'v';
            }
    }
    else if(*((char*)CarList->head->symbol) == '<'){
        if(map[*((int*)CarList->head->x )][*((int*)CarList->head->y )-1 ] == '.'){
          map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
          x = *((int*)CarList->head->x);
          y = *((int*)CarList->head->y) - 1;
          character = '<';
          }
          else if(map[*((int*)CarList->head->x )- 1][*((int*)CarList->head->y)] == '.'){
            map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
            x = *((int*)CarList->head->x) -1 ;
            y = *((int*)CarList->head->y);
            character = '^';
            }
          else if (map[*((int*)CarList->head->x )+ 1][*((int*)CarList->head->y)] == '.'){
            map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
            x = *((int*)CarList->head->x) + 1  ;
            y = *((int*)CarList->head->y);
            character = 'v';
            }
        
    }
    else if(*((char*)CarList->head->symbol) == '^'){
        if(map[*((int*)CarList->head->x )- 1 ][*((int*)CarList->head->y)] == '.'){
          map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
          x = *((int*)CarList->head->x) -1 ;
          y = *((int*)CarList->head->y);
          character = '^';
          }
          else if(map[*((int*)CarList->head->x)][*((int*)CarList->head->y )- 1] == '.'){
            map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
            x = *((int*)CarList->head->x);
            y = *((int*)CarList->head->y) - 1 ;
            character = '<';
            }
          else if (map[*((int*)CarList->head->x)][*((int*)CarList->head->y) + 1 ] == '.'){
            map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
            x = *((int*)CarList->head->x);
            y = *((int*)CarList->head->y) + 1 ;
            character = '>';
            }
        
    }
    else {
        if(map[*((int*)CarList->head->x)+ 1 ][*((int*)CarList->head->y)] == '.'){
          map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
          x = *((int*)CarList->head->x) + 1 ;
          y = *((int*)CarList->head->y);
          character = 'v';
          }
          else if(map[*((int*)CarList->head->x)][*((int*)CarList->head->y )- 1] == '.'){
            map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
            x = *((int*)CarList->head->x);
            y = *((int*)CarList->head->y) - 1 ;
            character = '<';
            }
          else if (map[*((int*)CarList->head->x)][*((int*)CarList->head->y) + 1 ] == '.'){
            map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = '.';
            x = *((int*)CarList->head->x);
            y = *((int*)CarList->head->y) + 1 ;
            character = '>';
            }   
      }
      insertFirst(CarList, (&x), (&y), (&character));
      map[*((int*)CarList->head->x)][*((int*)CarList->head->y)] = *((char*)CarList->head->symbol) ;
    
}
