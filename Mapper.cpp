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
#include <unistd.h> 
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
        cout << "\t6: Chargement d'un catalogue de trajets" << endl;
        cout << "\t7: sauvegarde du catalogue courant" << endl;
        cout << "\t0: Quitter l'application Mapper" << endl;

        char choix;
        cin>>choix;
        cin.ignore();

        switch (choix) {
            case '0':
                end=true;
                break;
            case '1':
                catalogue.AddTrajetSimple();
                break;
            case '2':
                catalogue.AddTrajetCompose();
                break;
            case '3':
                cout << catalogue;
                break;
            case '4':
                catalogue.RechercheSimple();
                break;
            case '5':
                catalogue.RechercheComplexe();
                break;
            case '6':
            {
                cout<<"Entrez le nom de ficher(avec l'extension) pour le chargement:"<<endl;
                string nomFicher;
                cin>>nomFicher;
                //si le nonFicher existe ;  R_OK l'acces read ,oui -> 0 , n'existe pas ou pas de droit de read -> -1
                /*if(access("nomFicher", R_OK) == -1 ){
                    cout << "Saisie du ficher n'existe pas ou sans droit de lecture. Recommencer." << endl;
                    continue;
                }*/
                
                cout<<"Entrez le type de chargement :"<<endl;
                cout<<"1. Sans critère de sélection"<<endl;
                cout<<"2. Selon le type des trajets"<<endl;
                cout<<"3. Selon la ville de départ et / ou la ville d'arrivée"<<endl;
                cout<<"4. Selon une sélection de trajets"<<endl;
                cin>>choix;
                switch(choix){
                    case '1':
                    catalogue.Sauvegarde(nomFicher,catalogue::SANS); 
                    break;
                    case '2':
                    catalogue.Sauvegarde(nomFicher,catalogue::TYPE); 
                    break;
                    case '3':
                    catalogue.Sauvegarde(nomFicher,catalogue::VILLE); 
                    break;
                    case '4':
                    catalogue.Sauvegarde(nomFicher,catalogue::TRAJETS); 
                    break;
                    default:
                    cout << "Saisie du choix incorrect. Recommencer." << endl;
                    continue;
                }
                break;
            }
            case '7':
            {
                cout<<"Entrez le nom de ficher(avec l'extension) pour la sauvegarde:"<<endl;
                string nomFicher;
                cin>>nomFicher;
                //si le nonFicher existe ;  F_OK exisitance , oui -> 0 , non -> -1
                /*if(access( "nomFicher" , F_OK) == 0 ){
                    cout << "Saisie du nom de ficher existe déjà. Recommencer." << endl;
                    continue;
                }*/
                
                cout<<"Entrez le type de sauvegarde :"<<endl;
                cout<<"1. Sans critère de sélection"<<endl;
                cout<<"2. Selon le type des trajets"<<endl;
                cout<<"3. Selon la ville de départ et / ou la ville d'arrivée"<<endl;
                cout<<"4. Selon une sélection de trajets"<<endl;
                cin>>choix;
                switch(choix){
                    case '1':
                    catalogue.Charge(nomFicher,catalogue::SANS); 
                    break;
                    case '2':
                    catalogue.Charge(nomFicher,catalogue::TYPE); 
                    break;
                    case '3':
                    catalogue.Charge(nomFicher,catalogue::VILLE); 
                    break;
                    case '4':
                    catalogue.Charge(nomFicher,catalogue::TRAJETS); 
                    break;
                    default:
                    cout << "Saisie du choix incorrect. Recommencer." << endl;
                    continue;
                }
                break;
            }
            default:
            {
                cout << "Saisie du choix incorrect. Recommencer." << endl;
                continue; //Revient au début du menu.
            }
        }
    }

    return EXIT_SUCCESS;
}
