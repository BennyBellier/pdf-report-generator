/* ------------------------------------------------------------------------
-- paquetage core
--
-- paramètre du programme
--
-- B. Bellier (version intiale) : septembre 2021
--
-- Version 1.0 : language C
----------------------------------------------------------------------- */
#ifndef __CORE_H__
#define __CORE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#ifndef VERSION
#define VERSION ((double)1.0)
#endif

#ifndef MAX_ENTRY
#define MAX_ENTRY 2056 // Definition de la taille maximum d'une entree de l'utilisateur
#endif

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

typedef enum // Entries
{
  GENERATE,   //generate ...
  SETTITLE,   // settitle
  SETNAMES,   // setnames
  HELP,       //h, help
  WAIT_ENTER, //
  EXIT,       // q, quit
  BLANK,      //
  ERROR,      // unknown
} Entries;

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

// Format la date au moment de l'execution pour l'impression dans le fichier
char *datage();

/* --------------------------------------------------------------------- */

// Formate les noms entrees en parametres pour l'impression dans le fichier
char *nommage(int argc, char *noms[]);

/* --------------------------------------------------------------------- */

// Formatte le titre pour l'impression dans le fichier
char *titrage(int argc, char *titre[]);

/* --------------------------------------------------------------------- */



#endif
