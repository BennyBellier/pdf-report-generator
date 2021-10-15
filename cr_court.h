/* ------------------------------------------------------------------------
-- paquetage core
--
-- genere un pdf LaTeX court
--
-- B. Bellier (version intiale) : septembre 2021
--
-- Version 1.0 : language C
----------------------------------------------------------------------- */
#ifndef __CR_COURT_H__
#define __CR_COURT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "core.h"

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

// Genere le fichier .tex
void generate_court(char *f);

/* --------------------------------------------------------------------- */

int main(int argc, char const *argv[]);


#endif
