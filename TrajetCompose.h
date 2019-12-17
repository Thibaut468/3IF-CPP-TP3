/*************************************************************************
                       TrajetCompose  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

#include "Trajet.h"
#include "ListeTrajets.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Classe qui hérite de Trajet: représente un trajet d'une ville A à une Ville B,
// et ce en passant par des villes intermédiaires. Les trajets intermédiaires sont
// représentés par des trajets simples, avec une ville de départ, d'arrivée et un
// moyen de transport. TrajetCompose est donc une liste de Trajets simples.
// Elle a deux attributs: un objet ListeTrajet et un nombre de trajets
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Affichage () const;
    // Mode d'emploi :
    // Affiche la liste des trajets simples qui composent le trajet composé,
    // avec la ville de départ, les villes intermédaires et les moyens de transport
    // utilisés pour les rejoindres, ainsi que la ville d'arrivée
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose (const TrajetCompose & unTrajetCompose);
    // Mode d'emploi : Constructeur de copie: permet de créer un  nouveau
    // trajetCompose en copiant les attributs d'un trajetCompose déjà existant
    // Paramètre entrant: un Objet TrajetCompose
    // Contrat :
    //

    TrajetCompose ( const char* vDepart, const char* vArrivee, ListeTrajets* liste);
    // Mode d'emploi : Crée un trajetCompose à partir d'une ville de départ,
    // d'arrivée et d'une liste de trajet simples.
    // Parametre entrant: deux chaines de caractères représentant une ville de départ
    // et d'arrivée, et un pointeur vers une listeTrajet contenant les trajets qui compose l'objet.
    // Contrat :
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi : Désalloue la mémoire réservée par un trajet composé
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ListeTrajets* etapes;
    int nbTrajets;

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H
