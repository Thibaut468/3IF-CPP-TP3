/*************************************************************************
                       Trajet  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::Affichage () const
// Algorithme :
// affichage dans la console des attributs
{

    cout << "Trajet de " << villeDepart << " à " << villeArrivee;
} //----- Fin de Affichage

char* Trajet::GetVilleDepart () const
{
    return villeDepart;
} //----- Fin de GetVilleDepart

char* Trajet::GetVilleArrivee () const
{
    return villeArrivee;
} //----- Fin de GetVilleArrivee


//-------------------------------------------- Destructeurs

Trajet::~Trajet ( )
// Algorithme :
// Destrcteur de la classe: delete des deux chaines de caractère: villeDepart
// et villeArrivee
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif

    delete [] villeDepart;
    delete [] villeArrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//-------------------------------------------- Constructeurs

Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
// Constructeur de copie de Trajet: attribut deux nouvelles case mémoires pour
//les attributs villeDepart et villeArrivee et copie les valeurs du Trajet en
//paramètre avec strcpy.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
    villeDepart = new char [strlen(unTrajet.villeDepart) + 1];
    villeArrivee = new char [strlen(unTrajet.villeArrivee) + 1];
    strcpy ( villeDepart, unTrajet.villeDepart );
    strcpy ( villeArrivee, unTrajet.villeArrivee );

} //----- Fin de Trajet (constructeur de copie)

Trajet::Trajet ( const char* vDepart, const char* vArrivee )
// Algorithme :
// Constructeur de la classe: attribut deux cases mémoires de la taille des
//chaines de charactere  pour villeDepart et villeArrivee, et copie les chaines
// de caractère avec strcpy.
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    villeDepart = new char [strlen(vDepart) + 1];
    villeArrivee = new char [strlen(vArrivee) + 1];
    strcpy ( villeDepart, vDepart );
    strcpy ( villeArrivee, vArrivee );

} //----- Fin de Trajet