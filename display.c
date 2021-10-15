/* ------------------------------------------------------------------------
-- paquetage display
--
-- affichage navigation
--
-- B. Bellier (version intiale) : septembre 2021
--
-- Version 1.0 : language C
----------------------------------------------------------------------- */

#include "display.h"

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

void display_start()
{
  fprintf(stdout, "\n\tC R G E N");
  fprintf(stdout, "\n\tVersion %.1f\t last modified 2021-09-21\n", VERSION);
  fprintf(stdout, "\n\tAuthor:\n");
  fprintf(stdout, "\tBenjamin Bellier\n");
  fprintf(stdout, "\n\timmediate help:\t type \"help\" (plot window: hit \'h\')\n\n");
}

/* --------------------------------------------------------------------- */

void display_cursor()
{
  fprintf(stdout, "crgen> ");
}

/* --------------------------------------------------------------------- */

void display_wrong_entry()
{
  fprintf(stdout, "       ^\n       invalid command\n");
}

/* --------------------------------------------------------------------- */

void display_help()
{
  fprintf(stdout, "\'Crgen\' est un assistant generateur de pdf avec LaTeX pour Linux.\n");
  fprintf(stdout, "");
}
