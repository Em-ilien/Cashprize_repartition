/* 

(C) Emilien Cosson - 2023

Cet algorithme calcule la répartition d'un cashprize entre plusieurs joueurs.

Il suffit de lui fournir le montant total du cashprize, ainsi que le nombre de vainqueurs
qui se le partageront.

La répartition se fait comme suit :
le grand vainqueur (1er) gagne deux fois plus que le 2e ;
quatre fois plus que le 3e ;
huit fois plus que le 4e ;
...

Pour afficher les coefficients correspondant, saissisez un cashprize de 1 €.

*/


#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

#define TEMPS_ENTRE_LES_OUTPUT 1.00

float total;
int nb_joueurs;

float get_difference(float j1, int nb_joueurs) {
    float difference = total;

    for (int i = 0; i < nb_joueurs; i++) {
        difference -= j1 / pow(2, i);
    }

    return difference;
}

int calcul(int nb_joueurs) {
    float* joueurs = new float[nb_joueurs];
    float difference = total;

    for (int i = 0; i < nb_joueurs; i++) {
        joueurs[i] = 0;
    }

    while (get_difference(joueurs[0], nb_joueurs) > 0.00001) {
        float div_temp = 0;
        for (int j = 0; j < nb_joueurs; j++) {
            div_temp = joueurs[0] / pow(2, j);
            joueurs[j] = div_temp;
        }

        float somme = 0;
        for (int i = 0; i < nb_joueurs; i++) {
            somme += joueurs[i];
        }

        if (abs(somme - total) < 0.00001) {
            break;
        }

        if (somme < total) {
            joueurs[0] += fabs(difference / 2);
        }
        else {
            joueurs[0] -= fabs(difference / 2);
        }

        difference = get_difference(joueurs[0], nb_joueurs);
    }

    printf("\nRépartition :\n");
    printf("1er : %.2f\n", joueurs[0]);

    for (int i = 1; i < nb_joueurs; i++) {
        printf("%de  : %.2f\n", (i + 1), joueurs[i]);
    }

    printf("\n(i) précision : %.2f\n", difference);

    delete[] joueurs;

    return 0;
}
  
int main() {
    setlocale(LC_ALL, "fr_FR.UTF-8");

    printf("\n(C) Emilien Cosson  -  2023\n\n");
    Sleep(250 * TEMPS_ENTRE_LES_OUTPUT);

    printf("Bonjour,\n");
    Sleep(1000 * TEMPS_ENTRE_LES_OUTPUT);

    printf("\nCet algorithme permet de répartir un cashprize entre plusieurs joueurs.\n");
    Sleep(2000 * TEMPS_ENTRE_LES_OUTPUT);

    printf("\n\nCombien y a-t-il de cashprize à partager, en euros ?\n");
    printf("\n(i) Pour obtenir un pourcentage, saisissez 100.\n    Pour un coefficient, saisissez 1.\n");
    Sleep(1750 * TEMPS_ENTRE_LES_OUTPUT);
    printf("\n » total= ");
    scanf_s("%f", &total);
    Sleep(500 * TEMPS_ENTRE_LES_OUTPUT);

    printf("\n\n\nLes %.2f € sont à partager entre combien de vainqueurs sur le podium ?\n", total);
    Sleep(1750 * TEMPS_ENTRE_LES_OUTPUT);
    printf("\n » nb_joueurs= ");
    scanf_s("%d", &nb_joueurs);
    Sleep(500 * TEMPS_ENTRE_LES_OUTPUT);

    printf("\n\nMerci beaucoup. Calcul en cours...\n");
    Sleep(2500 * TEMPS_ENTRE_LES_OUTPUT);

    printf("===================\n");
    Sleep(750 * TEMPS_ENTRE_LES_OUTPUT);

    return calcul(nb_joueurs);
}