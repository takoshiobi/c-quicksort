#include <stdio.h>
#include "test.h"

int partitionner(int *tab, int p, int r) {
    int pivot = tab[p], i = p-1, j = r+1;
    int temp;
    while (1) {
        do
            j--;
        while (tab[j] > pivot);
        do
            i++;
        while (tab[i] < pivot);
        if (i < j) {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
        else
            return j;
    }
}

void quicksort_aux(int *tab, int p, int r){
  int q;
  if (p<r){
    q = partitionner(tab, p, r);
    quicksort_aux(tab, p, q);
    quicksort_aux(tab, q+1, r);
  }
}

void quicksort_int(int *tab, unsigned int nelem){
  quicksort_aux(tab,0,nelem-1);
}
