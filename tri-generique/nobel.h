#define MAXTAB (2040-1901)*3*5

#define compare(a,b) \
  if (a<b) return -1; \
  if (a>b) return 1;

enum genre {male, female};
enum categorie {physics,literature,chemistry,peace,medicine};

typedef struct {
  int year_prix;
  enum categorie cat;
  char name[100];
  char country[30];
  enum genre g;
  int jour;
  int mois;
  int annee;} Nomine_s;
