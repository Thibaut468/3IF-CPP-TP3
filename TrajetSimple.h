/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

#include "Trajet.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// TrajetSimple est une classe qui hérite de Trajet: c'est un objet qui
// représente un trajet d'une ville A vers une ville B réalisé par un moyen
// de transport.
//  Elle comporte un attribut: une chaine de caractère décrivant le moyen de
// transport. Elle hérite également des chaines de caractère villeDepart et
// villeArrivee de la classe Trajet

//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Affichage() const;
    // Mode d'emploi :
    // Méthode affiche les attributs de la classe: la ville de départ et d'arrivée
    //ainsi que le moyen de transport
    // Contrat :
    //

    char* GetMoyenTransport() const;
    // Mode d'emploi :
    // Un getteur qui permet d'obtenir l'attribut moyen de transport
    // Contrat :
    //

    virtual string GetType() const;
    // Mode d'emploi :
    // Un getteur qui permet d'obtenir le type de trajet
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple (const TrajetSimple & unTrajetSimple);
    // Mode d'emploi :
    // Permet de créer un nouveau trajet en  copiant
    // les attributs d'un trajet simple déjà existant
    // Contrat :
    //

    TrajetSimple (const char* vDepart, const char* vArrivee, const char* mTransport);
    // Mode d'emploi :
    // Crée un trajet simple à partir de chaines de caractère représentant
    // une ville de départ, d'arrivée et un moyen de transport
    // Contrat :
    //

    virtual ~TrajetSimple();
    // Mode d'emploi :
    // Détruit la mémoire allouée à un trajet simple
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char* moyenTransport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
