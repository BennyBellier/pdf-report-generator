/* ------------------------------------------------------------------------
-- paquetage core
--
-- paramètre du programme
--
-- B. Bellier (version intiale) : septembre 2021
--
-- Version 1.0 : language C
----------------------------------------------------------------------- */

#include "core.h"

char *date;
char *colaborateur;
char *title;

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

char *datage()
{
  const char *month[] = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet",
                         "Août", "Septembre", "Octobre", "Novembre", "Décembre"};
  char year[5];

  time_t timestamp = time(NULL);                // Recuperation de la date au moment de l'execution
  struct tm *timeInfos = localtime(&timestamp); // du programme et la stock dans timeInfos

  date = malloc(sizeof(char) * (strlen(month[timeInfos->tm_mon])+6));

  sprintf(year, "%d", timeInfos->tm_year + 1900); // Passage de int vers char pour l'annee

  strcpy(date, month[timeInfos->tm_mon]); // Ajout du mois a la chaine date
  strcat(date, " ");                      //
  strcat(date, year);                     // Ajout de l'annee a la chaine date
  date[strlen(date) - 1] = '\0';
}

/* --------------------------------------------------------------------- */

char *nommage(int argc, char *noms[])
{
  int len_colab = 0;
  for (int i = 0; i < argc; i++)
  {
    len_colab += strlen(noms[i]);
    if (i % 2 == 1)
      len_colab += 2;
  }

  colaborateur = malloc(sizeof(char) * len_colab + 1);

  for (int i = 0; i < argc; i += 2)
  {
    strcat(colaborateur, noms[i]);
    strcat(colaborateur, " ");
    strcat(colaborateur, noms[i + 1]);
    strcat(colaborateur, "\\\\");
  }
  colaborateur[strlen(colaborateur) - 1] = '\0';
}

/* --------------------------------------------------------------------- */

char *titrage(int argc, char *titre[])
{
  int len_title = 0;
  for (int i = 0; i < argc; i++)
  {
    len_title += strlen(titre[i]);
    len_title++; // ' '
  }

  title = malloc(sizeof(char) * len_title);

  for (int i = 0; i < argc; i++)
  {
    strcat(title, titre[i]);
    strcat(title, " ");
  }
  title[strlen(title) - 1] = '\0';
}
