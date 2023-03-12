# (C) Emilien Cosson  -  2023

"""

Cet algorithme calcule la répartition d'un cashprize entre plusieurs joueurs.

Il suffit de lui fournir le montant total du cashprize, ainsi que le nombre de vainqueurs
qui se le partageront.

La répartition se fait comme suit :
le grand vainqueur (1er) gagne deux fois plus que le 2e ;
quatre fois plus que le 3e ;
huit fois plus que le 4e ;
...

Pour afficher les coefficients correspondant, saissisez un cashprize de 1 €.

"""

import time

# pour supprimer le temps d'attente entre les indications, mettez 0
TEMPS_ENTRE_LES_OUTPUT = 1.00

T = TEMPS_ENTRE_LES_OUTPUT

print("\n(C) Emilien Cosson  -  2023\n\n")
time.sleep(0.25 * T)

print("Bonjour,")
time.sleep(1 * T)

print("\nCet algorithme permet de répartir un cashprize entre plusieurs joueurs.")
time.sleep(2 * T)

print("\n\nCombien y a-t-il de cashprize à partager, en euros ?")
print("\n(i) Pour obtenir un pourcentage, saisissez 100.\n    Pour un coefficient, saisissez 1.\n")
time.sleep(1.75 * T)
total = float(input(" » total="))
time.sleep(0.5 * T)

print("\n\nLes", total, "€ sont à partager entre combien de vainqueurs sur le podium ?\n")
time.sleep(1.75 * T)
nb_joueurs = int(input(" » nb_joueurs="))
time.sleep(0.5 * T)

print("\n\nMerci beaucoup. Calcul en cours...\n")
time.sleep(2.5 * T)

print("===================\n")
time.sleep(0.75 * T)

#appel de la fonction calcul après définition :

def calcul(TOTAL = 1, NB_JOUEURS = 3):
  joueurs = [0] * NB_JOUEURS
  
  def get_difference():
    difference = TOTAL
    
    for i in range(0, len(joueurs)):
      difference -= joueurs[0]/pow(2, i)
    
    return difference
  
  difference = get_difference()

  while(get_difference() != 0):
    for j in range(0, len(joueurs)):
      joueurs[j] = joueurs[0]/pow(2, j)
    
    somme = 0
    for i in range(0, len(joueurs)):
      somme += joueurs[i]
  
    if (somme == TOTAL):
      break
    
    if (somme < TOTAL):
      joueurs[0] += abs(difference/2)
    else:
      joueurs[0] -= abs(difference/2)
  
    difference = get_difference()
  
  difference = get_difference()
  print("\nRépartition :")
  
  print("1er :", joueurs[0])
  for i in range(1, len(joueurs)):
    print((i+1), "e  : ", joueurs[i], sep="")
  print("\n(i) précision :", difference)


calcul(total, nb_joueurs)