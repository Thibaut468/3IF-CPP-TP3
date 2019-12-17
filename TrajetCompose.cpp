/*************************************************************************
                   TrajetCompose  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Affichage () const
// Algorithme :
// fait appel a l'affichage de la classe mère Trajet pour afficher les villes de
// départ et d'arrivée dans la console à l'aide de Cout
//  Appelle ensuite l'affichage de chaque TrajetSimple composant
// la liste des trajets composés
{
    Trajet::Affichage();

    cout <<". Trajet composé de " << etapes->GetNbTrajets() << " étapes :" << endl;

    for(int i=0;i<etapes->GetNbTrajets();i++)
    {
        cout << "     " << "Etape " << i+1 << " : ";
        etapes->GetListe()[i]->Affichage();
    }

    //Affichage des etapes
} //----- Fin de Affichage

int TrajetCompose::GetNbTrajets() const
{
    return nbTrajets;
} //----- Fin de GetNbTrajets

ListeTrajets* TrajetCompose::GetEtapes() const
{
    return etapes;
} //----- Fin de GetEtapes


string TrajetCompose::GetType() const
{
    return "TC";
} //------ Fin de GetType

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const TrajetCompose & unTrajetCompose ) : Trajet(unTrajetCompose.villeDepart,unTrajetCompose.villeArrivee)
// Algorithme :
// Constructeur de copie: Parametres: Un objet TrajetCompose
//on récupère les attributs du trajetCompose existant, et on affecte ces attributs au nouveau TrajetCompose.
//On appelle le constructeur de Trajet pour les villes de départ et d'arrivée, et on appelle le constructeur de copie de ListeTrajets pour
// Créer une nouvelle liste trajet contenant les mêmes trajets.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet Compose>" << endl;
#endif

    *etapes=ListeTrajets(*unTrajetCompose.etapes);

} //----- Fin de Trajet Compose (constructeur de copie)

TrajetCompose::TrajetCompose (const char* vDepart, const char* vArrivee, ListeTrajets * liste) : Trajet(vDepart , vArrivee)
// Algorithme:
// Constructeur de TrajetCompose. On appelle le constructeur de Trajet (classe mère) pour affecter les attributs VilleDépart et villeArrivee
// et on affecte la valeur de liste (un pointeur vers ListeTrajet) à l'attribut "etapes". Pour obtenir le nombre de trajet, on appelle la méthode de
//ListeTrajets nous renvoyant le nombre de trajet correspondant
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

    etapes=liste;
    nbTrajets=etapes->GetNbTrajets();

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    for(int i=0;i<etapes->GetNbTrajets();i++)
        delete etapes->GetListe()[i];

    delete etapes;

} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
