#include <stdlib.h>
#include <stdio.h>
#include "test.h"

int main (void){
  int tab[TABSIZE];

  int i;
  for(i=0; i<10; i++){
    tab[i]=rand()% 100;
  }

  quicksort_int(tab, TABSIZE);

  for(i=0; i<TABSIZE; i++){
    printf("%d\n",tab[i]);
  }


}
