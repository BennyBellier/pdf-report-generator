/* ------------------------------------------------------------------------
-- paquetage main_crgen
--
-- analyse et execution de la requête utilisateur
--
-- B. Bellier (version intiale) : septembre 2021
--
-- Version 1.0 : language C
----------------------------------------------------------------------- */

#include "main_crgen.h"

Entries Entry;
bool run = true;
char buffer[MAX_ENTRY];

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

int main()
{
  display_start();

  do
  {
    display_cursor();

    /* --------------------- SAISIE --------------------- */
    fgets(buffer, MAX_ENTRY, stdin);  // recuperation de la saisie de l'utilisateur
    entry_type(strtok(buffer, "\n")); // Supprime tout caractere apres la pression de la touche entree

    /* --------------------- EXECUTION --------------------- */
    execute_entry();

  } while (run);

  return 0;
}

/* --------------------------------------------------------------------- */

void entry_type(char *buffer)
{
  if (buffer == NULL)
    Entry = BLANK;
  else
  {
    bool change = true;
    if (strcmp(&buffer[0], "h") == 0 || strcmp(&buffer[0], "help") == 0)
      Entry = HELP;
    else if (strcmp(&buffer[0], "q") == 0 || strcmp(&buffer[0], "quit") == 0 || strcmp(&buffer[0], "exit") == 0)
      Entry = EXIT;
    else if (strcmp(&buffer[0], "setnames") == 0)
      Entry = SETNAMES;
    else if (strcmp(&buffer[0], "settitle") == 0)
      Entry = SETTITLE;
    else if (strcmp(&buffer[0], "generate") == 0)
      Entry = GENERATE;
    else
      change = false;

    if (!change)
    {
      Entry = ERROR;
    }
  }
}

/* --------------------------------------------------------------------- */

void execute_entry()
{
  switch (Entry)
  {
  case EXIT:
    run = false;
    break;
  case HELP:
    display_help();
    break;
  
  case ERROR:
  default:
    display_wrong_entry();
    break;
  }
}
