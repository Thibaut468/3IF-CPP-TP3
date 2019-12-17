/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ListeTrajets::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Trajet ** ListeTrajets::GetListe() const
// Algorithme :
//
{
    return liste;
} //----- Fin de GetListe

int ListeTrajets::GetNbTrajets() const
// Algorithme :
//
{
    return nbTrajets;
} //----- Fin de getNbTrajets

void ListeTrajets::AddTrajet(Trajet* nouveauTrajet)
// Algorithme :
// Si la quantitée de mémoire allouée n'est pas suffisante pour ajouter un trajet supplémentaire,
// On appelle une méthode augmenterTaille pour augmenter la taille allouée.
// On ajoute ensuite le pointeur vers trajet (obtenu en paramètre) au tableau dynamique
{
    if(nbTrajets==tailleMax)
    {
        augmenterTaille();
    }

    liste[nbTrajets] = nouveauTrajet;
    nbTrajets=nbTrajets+1;
} //----- Fin de addTrajet

int ListeTrajets::RetirerDernier()
// Algorithme :
// On diminue le nombre de trajets pour ne pas prendre en compte le dernier trajet
// cela ne provoque pas de fuite de mémoire car cette méthode n'est appellée que dans le cas
// d'une copie de liste : il existe toujours d'autre pointeurs permettant de détruire ces trajets part
// la suite dans la liste d'origine.
{
    nbTrajets--;
    return 0;
} //----- Fin de Retirer

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

ListeTrajets::ListeTrajets (const ListeTrajets & unListeTrajets)
// Algorithme :
// On recopie les éléments de la liste passée en paramètre un par un (parcours en prodondeur)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeTrajets>" << endl;
#endif

    liste = new Trajet * [unListeTrajets.tailleMax];
    tailleMax=unListeTrajets.tailleMax;
    nbTrajets=unListeTrajets.nbTrajets;
    for(int i=0;i<unListeTrajets.nbTrajets;i++)
    {
        liste[i] = unListeTrajets.GetListe()[i];
    }
} //----- Fin de ListeTrajets (constructeur de copie)


ListeTrajets::ListeTrajets (const int taille) : tailleMax(taille), nbTrajets(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif

    liste = new Trajet * [tailleMax];
} //----- Fin de ListeTrajets


ListeTrajets::~ListeTrajets ()
// Algorithme :
// On supprime seulement le tableau dynamique, pas les trajets stockés dedans. 
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif
    delete [] liste;
} //----- Fin de ~ListeTrajets


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void ListeTrajets::augmenterTaille()
// Algorithme :
// On recrée un nouveau tableau dynamique, plus grand de NBAUGMENTATION que le tableau actuel.
// On copie ensuite un a un les pointeurs vers trajet.
{
    tailleMax+=NBAUGMENTATION;

    Trajet ** tmp = new Trajet * [tailleMax];

    for(int i = 0; i<nbTrajets;i++)
    {
        tmp[i]=liste[i];
    }

    delete [] liste;

    liste=tmp;
} //----- Fin de GetListe
