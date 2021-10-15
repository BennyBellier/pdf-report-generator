/* ------------------------------------------------------------------------
-- paquetage display
--
-- affichage navigation
--
-- B. Bellier (version intiale) : septembre 2021
--
-- Version 1.0 : language C
----------------------------------------------------------------------- */
#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// #include "help.h"
#include "core.h"

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

// Affichage des informations de demarrage
void display_start();

/* --------------------------------------------------------------------- */

// Affichage de la ligne d'entree de l'utilisateur
void display_cursor();

/* --------------------------------------------------------------------- */

// Affiche que la command entree est invalide
void display_wrong_entry();

/* --------------------------------------------------------------------- */

void display_help();

#endif
