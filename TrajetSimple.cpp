/*************************************************************************
                        TrajetSimple  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void TrajetSimple::Affichage () const
// Algorithme :
// Appelle la méthode affichage de la classe mère afin d'afficher la ville de
// départ et d'arrivée, et affiche le moyen de transport dans la console.
{
    Trajet::Affichage();
    cout <<" en " << moyenTransport << endl;

} //----- Fin de Affichage

char* TrajetSimple::GetMoyenTransport() const
{
    return moyenTransport;
} //----- Fin de GetMoyenTransport

string TrajetSimple::GetType() const
{
    return "TS";
} //------ Fin de GetType


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const TrajetSimple &unTrajetSimple) : Trajet(unTrajetSimple.villeDepart,unTrajetSimple.villeArrivee)
// Algorithme :
// Constructeur de copie: crée un nouveau Trajet simple en copiant les Attributs
// d'un trajetSimple déjà existant à l'aide de strcpy.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet Simple>" << endl;
#endif

    moyenTransport = new char [strlen(unTrajetSimple.moyenTransport) + 1];
    strcpy( moyenTransport, unTrajetSimple.moyenTransport);


} //----- Fin de Trajet Simple (constructeur de copie)

TrajetSimple::TrajetSimple (const char* vDepart, const char* vArrivee, const char* mTransport) : Trajet(vDepart, vArrivee)
// Algorithme :
// Constructeur: fait appel au constructeur de la classe mère Trajet pour
// définir les villes de départ et d'arrivée, alloue de la mémoire dynamique
// pour la chaîne de caracatère représentant le moyen de transport, et copie
// cette chaine de caractère dans la mémoire à l'aide de strcpy.
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

    moyenTransport = new char [strlen(mTransport) + 1];
    strcpy( moyenTransport, mTransport);

} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme : Destructeur: désalloue la mémoire allouée à la chaine de caractère
// moyenTransport
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete [] moyenTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
