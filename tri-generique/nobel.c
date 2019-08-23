#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nobel.h"
#include "test2.h"

extern Nomine_s tab[MAXTAB];

void read_chaine(char tab[], int taille){
  int i;
  i=0;
  char c;
  do{
    c=getchar();
    if(c!='"'){
      tab[i++]=c;
    }
  }while(c!='"');
  tab[i]='\0';
  /* printf("\nchaine lue: [%s]\n", tab); */
}

int read_entier(){
  int resultat = 0;
  int c;
  c=getchar();
  // printf("read_entier:\n\n");
  while(c!=' ' && c!='"'&& c!='-' && c != 9){
    // printf("Je lis: %c (0x%x)\n", c, c);
    /*if (c < '0' || c > '9')
      abort();*/

    resultat=resultat*10+(c-'0');
    c=getchar();
  }
  //printf("%d", resultat);
  return resultat;
}


int ConstruireTableaux(Nomine_s tab[]){
  int i=0;
  int j;

  char c;
  while(c!=EOF){
    char tmp[100];
    //Récupération de l'année du prix
    tab[i].year_prix = read_entier();
    printf("%d ", tab[i].year_prix);

    //les guillemets entre la date et le domaine
    c = getchar();

    //Récupération du domaine
    read_chaine(tmp,20);
    if(!strcmp(tmp,"physics"))
      tab[i].cat=physics;
    else if(!strcmp(tmp,"peace"))
      tab[i].cat=peace;
    else if(!strcmp(tmp,"literature"))
      tab[i].cat=literature;
    else if(!strcmp(tmp,"chemistry"))
      tab[i].cat=chemistry;
    else if(!strcmp(tmp,"medicine"))
      tab[i].cat=medicine;


    //L'espace et les guillemets entre le domaine et le nom
    c = getchar();
    c = getchar();

    //Récupération du nom
    read_chaine(tmp,100);
    for (j=0; tmp[j]!='\0'; j++){
      tab[i].name[j]=tmp[j];
    }
    tab[i].name[j] = 0;
    printf("%s ", tab[i].name);

    //L'espace et les guillemets entre le nom et la date de naissance
    c = getchar();
    c = getchar();

    //Récupération de la date de naissance
    tab[i].annee=read_entier();
    tab[i].mois=read_entier();
    tab[i].jour=read_entier();
    printf("%d-%d-%d ", tab[i].annee, tab[i].mois, tab[i].jour);

    //On passe les caractères entre la date de naissance et le pays
    for (i=0; i<12; i++){
      c = getchar();
    }

    //Récupération du pays
    read_chaine(tmp,20);
    for (j=0; tmp[j]!='\0'; j++){
      tab[i].country[j]=tmp[j];
    }
    tab[i].country[j] = 0;
    printf("%s\n", tab[i].country);


    //L'espace et les guillemets entre le pays et le genre
    c = getchar();
    c = getchar();

    read_chaine(tmp,20);
    if(!strcmp(tmp,"male"))
      tab[i].g=male;
    else if (!strcmp(tmp,"female"))
      tab[i].g=female;

    i++;

    c = getchar(); // \n ou EOF selon si fin de fichier ou non
  }
  return i;
}

int CompareNomineParAgeDObtention(Nomine_s n1, Nomine_s n2){
  //struct Nomine_s *n1 = (struct Nomine_s*) v1;
  //struct Nomine_s *n2 = (struct Nomine_s*) v2;
  compare(n1.annee, n2.annee);
  compare(n1.mois, n2.mois);
  compare(n1.jour, n2.jour);
  return 0;
}
