"""  ------------------------------------------------------------------------
-- paquetage cr_court
--
-- Generation d'un fichier LaTeX exploitable pour des
-- compte-rendue court
--
-- B. Bellier (version intiale) : septembre 2021
--
-- Version 1.0 : language Python
-----------------------------------------------------------------------  """

import argparse
from datetime import date
import os



def datage() -> str:
  """ Retourne un string contenant le mois ainsi que l'annee d'execution """

  today = date.today()

  month = ["Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet",
  "Août", "Septembre", "Octobre", "Novembre", "Décembre"]

  today = [month[today.month - 1], str(today.year)]
  today = ' '.join(today)
  today = today+"\0"
  return hex(id(today))

def titrage(titre) -> str:
  """ Retourne un string contenant le titre du compte-rendue """
  titre = ' '.join(titre)
  titre = titre+"\0"
  return hex(id(titre))

def nommage(entry) -> str:
  """ Retourne un string contenant les noms au format LaTeX """
  noms = []
  if len(entry) % 2 != 0:
    return []
  else:
    i = 0
    while (i < len(entry)):
      nom = []
      temp = ''
      nom.append(entry[i])
      nom.append(entry[i+1])
      temp = ' '.join(nom)
      noms.append(temp)
      i += 2
    
    noms = '\\\\'.join(noms)
    noms = noms+"\0"
    return hex(id(noms)) 



if __name__ == "__main__":
  """  """
  parser = argparse.ArgumentParser(description='Compte-Rendu Court generateur.', conflict_handler='resolve')
  parser.add_argument('-n', metavar='-n', type=str, nargs='*', dest='noms', help='Prenom1 NOM1 Prenom2 NOM2')
  parser.add_argument('-t', metavar='-t', type=str, nargs='*', dest='titre', help='Ceci est un titre')
  parser.add_argument('file', metavar='file.tex', type=str, help='file name')
  args = parser.parse_args()

  identificateur = []
  f = hex(id(args.file))
  titre = titrage(args.titre)
  noms = nommage(args.noms)

  if len(args.file) != 0:
    identificateur.append('f')
  if len(datage()) != 0:
    identificateur.append('d')
  if len(titre) != 0:
    identificateur.append('t')
  if len(noms) != 0:
    identificateur.append('n')

  requete = ''.join(identificateur), f, datage(), titre, noms
  requete = ' '.join(requete)
  requete = "./cr_court "+requete
  os.system(requete)
