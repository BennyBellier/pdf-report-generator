/* ------------------------------------------------------------------------
-- paquetage core
--
-- genere un pdf LaTeX court
--
-- B. Bellier (version intiale) : septembre 2021
--
-- Version 1.0 : language C
----------------------------------------------------------------------- */

#include "cr_court.h"
#include <string.h>

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

int main(int argc, char const *argv[])
{
  char *title = NULL;
  char *names = NULL;
  char *file_name = NULL;
  int i = 1;

  while (i < argc)
  {
    if (strrchr(argv[i], '.') != NULL)
    {
      file_name = malloc(sizeof(char) * (strlen(argv[i] + 1)));
      assert(file_name != NULL);
      strcpy(file_name, argv[i]);
    }
    if (strcmp(argv[i], "-t") == 0)
    {
      title = malloc(sizeof(char));
      assert(title != NULL);
      i++;
      while (argv[i] != NULL && strcmp(argv[i], "-n") != 0 && strrchr(argv[i], '.') == NULL)
      {
        title = realloc(title, sizeof(char) * (strlen(argv[i]) + 1));
        assert(title != NULL);
        strcat(title, argv[i]);
        strcat(title, " ");
        i++;
      }
      
    }
    if (strcmp(argv[i], "-n") == 0)
    {
      names = malloc(sizeof(char));
      assert(names != NULL);
      i++;
      while (argv[i] != NULL && strcmp(argv[i], "-t") != 0 && strrchr(argv[i], '.') == NULL)
      {

        names = realloc(names, sizeof(char) * (strlen(argv[i]) + 1));
        assert(names != NULL);
        strcat(names, argv[i]);
        strcat(names, " ");
        i++;
        names = realloc(names, sizeof(char) * (strlen(argv[i]) + 2));
        assert(names != NULL);
        strcat(names, argv[i]);
        strcat(names, "\\\\");
        i++;
      }
      names[strlen(names)-1] = '\0';
    }
    i++;
  }

  printf("%s\n%s\n%s\n", file_name, title, names);

  if (file_name == NULL)
    free(file_name);
  if (title == NULL)
    free(title);
  if (names == NULL)
    free(names);

  return 0;
}
