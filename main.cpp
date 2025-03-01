#include <iostream>
using namespace std;

#include "Sort.h"
#include "meal.h"
#include "ingredients.h"

int main(int argc, char* argv[]) {

/* 
I'll work on this, I'm planning to use the terminal and makefile

-print list from calories (lowest to highest or highest to lowest)
-print list from protein (lowest to highest or highest to lowest)
-input elements to create a meal, print the calories and protein

*/

//meal creationg with terminal
    int n =argc;  
    meal *m = new meal[n];  
    int index = 0;
    for (int i=1;i<argc;i++) {
        m[index].set_meal(argv[i]);
        index++;
    }


  
  

 


  



}

