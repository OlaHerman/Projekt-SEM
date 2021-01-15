#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../cJSON/cJSON.h"

#include "polecenia.h"
#include "mapa.h"

int main(int argc, char **argv)
{
  char *a = "qwerty_7.json";
  char buffer[2048];
  FILE *f = fopen(a, "r"); 
  fread(buffer,1,2048,f);
  fclose(f);
  Mapa *M;
  Mapa_explore *ME;
    for (int i=1;i<argc;i++)
    {
      if(strcmp(argv[i], "move") == 0)
      {
        move(a);

        M = wczytaj_json(M, buffer);

        //printf("%d %d %s %s %s %s %d %s %s\n", M->current_x, M->current_y, M->status, M->name, M->current_session, M->direction, M->step, M->field_type, M->field_bonus);

        Pole *P = stworz(M);
        wypisz(P);
      }

      if(strcmp(argv[i], "right") == 0)
      {
        right(a);
        M = wczytaj_json(M, buffer);
        //printf("%d %d %s %s %s %s %d %s %s\n", M->current_x, M->current_y, M->status, M->name, M->current_session, M->direction, M->step, M->field_type, M->field_bonus);

        Pole *P = stworz(M);
        wypisz(P);
      }

      if(strcmp(argv[i], "left") == 0)
      {
        left(a);
        M = wczytaj_json(M, buffer);
        //printf("%d %d %s %s %s %s %d %s %s\n", M->current_x, M->current_y, M->status, M->name, M->current_session, M->direction, M->step, M->field_type, M->field_bonus);

        Pole *P = stworz(M);
        wypisz(P);
      }

      if(strcmp(argv[i], "explore") == 0)
      {
        explore(a);
        ME = wczytaj_json_explore(ME, buffer);
        //printf("%d %d %d %d %d %d %s %s %s\n", ME->x[0], ME->x[1], ME->x[2], ME->y[0], ME->y[1], ME->y[2], ME->type[0], ME->type[1], ME->type[2]);

        Pole *P = stworz(M);
        wypisz(P);
      }

      if(strcmp(argv[i], "info") == 0)
      {
        info(a);
        M = wczytaj_json(M, buffer);
        //printf("%d %d %s %s %s %s %d %s %s\n", M->current_x, M->current_y, M->status, M->name, M->current_session, M->direction, M->step, M->field_type, M->field_bonus);

        Pole *P = stworz(M);
        wypisz(P);
      } 
    }
    return 0;
}