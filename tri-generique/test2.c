#include <stdlib.h>
#include <stdio.h>
#include "nobel.h"
#include "test2.h"


int main (){
  FILE* fichier = NULL;
  Nomine_s tab[MAXTAB];
  fichier = fopen("nobel6.txt", "r");
  //construction du tableau (défini dans nobel.c)
  if(fichier != NULL){
    int result = ConstruireTableaux(tab);
    printf("%d\n", result);
    quicksort(fichier, 787, 42, CompareNomineParAgeDObtention(fichier[MAXTAB], fichier[MAXTAB]));
  }
  fclose(fichier);
  return 0;
}
