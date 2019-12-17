/*************************************************************************
                   Mapper  -  Classe principale de gestion du catalogue
                           et de la demande de trajet
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Mapper> (fichier Mapper.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Fonctions publiques

int main()
{

    // CREER UNE CLASSE MENU
    bool end = false;

    Catalogue catalogue = Catalogue();

    while(!end)
    {
        cout << endl << "Menu:" << endl;
        cout << "\t1: Ajouter un trajet simple" << endl;
        cout << "\t2: Ajouter un trajet composé" << endl;
        cout << "\t3: Afficher le catalogue" << endl;
        cout << "\t4: Recherche simple" << endl;
        cout << "\t5: Recherche complexe" << endl;
        cout << "\t0: Quitter l'application Mapper" << endl;

        int choix;
        cin>>choix;
        cin.ignore();

        switch (choix) {
            case 0:
                end=true;
                break;
            case 1:
                catalogue.AddTrajetSimple();
                break;
            case 2:
                catalogue.AddTrajetCompose();
                break;
            case 3:
                cout << catalogue;
                break;
            case 4:
                catalogue.RechercheSimple();
                break;
            case 5:
                catalogue.RechercheComplexe();
                break;
            default:
                cout << "Saisie du choix incorrect. Recommencer." << endl;
                continue; //Revient au début du menu.
        }
    }

    return EXIT_SUCCESS;
}
