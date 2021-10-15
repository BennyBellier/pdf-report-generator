/* ------------------------------------------------------------------------
-- paquetage main_crgen
--
-- analyse et execution de la requête utilisateur
--
-- B. Bellier (version intiale) : septembre 2021
--
-- Version 1.0 : language C
----------------------------------------------------------------------- */
#ifndef __MAIN_CRGEN_H__
#define __MAIN_CRGEN_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "display.h"

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

// Execution du programme
int main();

/* --------------------------------------------------------------------- */

// Reconnait l'entree de l'utilisateur
void entry_type(char *buffer);

/* --------------------------------------------------------------------- */

// Execute la command entree
void execute_entry();

#endif
