/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if ! defined ( LISTETRAJETS_H )
#define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

const int NBAUGMENTATION = 10;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
//  ListeTrajet est un objet, qui permet de regrouper les différents trajets crées en une
// liste ordonnée. La structure utilisée pour stocker ces trajets est un tableau dynamique,
// Contenant des pointeurs vers les trajets. On a alors comme attributs un entier représentant
// le nombre de trajets stockés, un tableau dynamique contenant les pointeurs vers les Trajets,
// et un entier représentant la taille de mémoire à allouer au tableau pour stocker les trajets.
//
//------------------------------------------------------------------------

class ListeTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Trajet ** GetListe() const;
    // Mode d'emploi :
    // Getteur permetant d'obtenir l'attribut liste. On retourne une liste de type
    // Pointeur vers des pointeurs de Trajet
    //
    // Contrat :
    //

    int GetNbTrajets() const;
    // Mode d'emploi :
    //Getteur permettant d'obtenir le nombre de trajets contenu dans la liste.
    // Contrat :
    //

    void AddTrajet(Trajet* nouveauTrajet);
    // Mode d'emploi :
    // Permet d'ajouter des trajets à la liste. On prend en paramètre un Trajet (cela
    // peut être un élement héritant de trajet, soit un TrajetSimple ou un TrajetCompose)
    // et on l'ajoute à la liste.
    // Contrat :
    // On s'assure qu'il y a assez de mémoire allouée pour stocker le trajet. Sinon, on
    // alloue plus de mémoire

    int RetirerDernier();
    // Mode d'emploi :
    //  Méthode qui permet de retirer le dernier trajet de la liste
    // Contrat :
    // On s'assure que le trajet existe toujours dans la mémoire, on veut juste ne plus le prendre en compte
    // dans la liste

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    ListeTrajets ( const ListeTrajets & unListeTrajets);
    // Mode d'emploi :
    // Constructeur de copie: prend en paramètre une listeTrajets et copie ses attributs
    // dans le nouvel objet crée
    // Contrat :
    //

    ListeTrajets (const int taille = NBAUGMENTATION);
    // Mode d'emploi :
    // Constructeur: par défaut la liste est vide, et on alloue de la mémoire pour 10 trajets
    // Contrat :
    //

    virtual ~ListeTrajets ( );
    // Mode d'emploi :
    // Destructeur: on détruit la mémoire allouée à la liste de trajet, mais pas les trajet en eux mêmes
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    void augmenterTaille();
    // Mode d'emploi :
    // Permet d'augmenter la taille allouée dynamiquement à la liste quand celle ci
    // est pleine. On ajoute de la mémoire pour 10 trajets supplémentaires quand celle-ci
    // est pleine.
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés

    Trajet ** liste;
    int nbTrajets;
    int tailleMax;

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajets>

#endif // LISTETRAJETS_H
