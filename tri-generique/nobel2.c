#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nobel.h"

enum genre {male, female};
enum categorie {physics,literature,chemistry,peace,medicine};

typedef struct {
  int year_prix;
  enum categorie cat;
  char name[100];
  char country[30];
  enum genre g;
  char date[11]; } Nomine_s;

Nomine_s tab[MAXTAB];

int read_entier(){
  int resultat = 0;
  int c;
  c=getchar();
  while(c!=' ' && c!='"'&& c!='-'){
    resultat=resultat*10+(c-'0');
    c=getchar();
  }
  //printf("%d", resultat);
  return resultat;
}

enum categorie read_domaine(){
  int i;
  char c = getchar();
  if (c=='L'){
    int i;
    for (i=0; i<12;i++) c = getchar();  //on passe les autres caractères et on passe à l'étape suivante
    return literature;
  }
  else if (c=='C'){
    for (i=0; i<11;i++) c = getchar();
    return chemistry;
  }
  else if (c=='P'){
    c = getchar();

    if (c=='e'){
      for (i=0; i<6;i++) c = getchar();
      return peace;
    }
    else { //Physics ou Physiologie ?
      for (i=0; i<4;i++) c = getchar();
      if (c=='c'){
        for (i=0; i<4;i++) c = getchar();
        return physics;
      }
      else{
        for (i=0; i<19;i++) c = getchar();
        return medicine;
      }
    }
  }
}

// void read_chaine(char tmp[], int taille){
//   int i;
//   char c;
//   c = getchar();
//   while (c!='"'){
//     tmp[i]=c;
//     i++;
//     c = getchar();
//   }
//   for (;i<taille;i++){
//     tmp[i]=0;
//   }
// }

void read_chaine(char tab[], int taille){
  int i;
  i=0;
  char c;
  do{
    c=getchar();
    tab[i++]=c;
    }while(c!='"');

}


int ConstruireTableaux(Nomine_s tab[]){
  char c;
  int i = 0;
  char tmp[100];
  while (c!=EOF){

    //Récupération de la date
    tab[i].year_prix = read_entier();
    printf("%d", tab[i].year_prix);

    //L'espace et les guillemets entre la date et le domaine
    c = getchar();
    c = getchar();

    //Récupération du domaine
    tab[i].cat = read_domaine();

    //Récupération du nom
    read_chaine(tmp, 100);
    int j;
    for (j=0; tmp[j]!='"'; j++){
      tab[i].name[j]=tmp[j];
    }
    printf("%s", tab[i].name);

    //Espace et guillemets entre nom et date de naissance
    c = getchar();
    c = getchar();

    //Récupération de la date de naisssance
    read_chaine(tmp, 100);
    for (j=0; tmp[j]!='"'; j++){
      tab[i].date[j]=tmp[j];
    }
    printf("%s", tab[i].date);

    i++;
    c = getchar();
  }
}


int main(){
  ConstruireTableaux(tab);

  //char tmp_nom[100];
  //read_chaine(tmp_nom, 100);
  //printf("%s", tmp_nom);
}
