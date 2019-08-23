#include <stdlib.h>
#include <stdio.h>

int partition(void *base, int p, int r, int(*compar)(const void *, const void *)) {
    char* tab = base;
    int pivot = tab[p];
    int i = p-1, j = r+1;
    int temp;
    while (1) {
        do{
            j--;
        }while (compar(&tab[j],&pivot)==1);
        do{
            i++;
        }while (compar(&tab[i],&pivot)==-1);
        if (i < j) {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
        else{
            return j;
          }
    }
}

void quicksort_aux(void *base, int p, int r, int(*compar)(const void *, const void *)){
  int q;
  if (p<r){
    q = partition(base, p, r, compar);
    quicksort_aux(base, p, q, compar);
    quicksort_aux(base, q+1, r, compar);
  }
}

void quicksort(void *base, int nelem, int size, int(*compar)(const void *, const void *)){
  quicksort_aux(base,0,nelem-1, compar);
}
