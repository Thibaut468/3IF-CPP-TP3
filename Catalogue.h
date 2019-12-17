/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <fstream>
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

enum CritereSelection {SANS, TYPE, VILLE, TRAJETS};

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Catalogue est la classe principale de l'application: elle possède un seul attribut qui est
// un objet ListeTrajets
// elle contient les méthodes permettant de créer de nouveaux trajets, ainsi que de rechercher
// des trajets simples et complexes, et enfin une méthode permettant d'afficher les trajets existants
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int Sauvegarde(string cheminAcces, CritereSelection critere);
    // Mode d'emploi :
    //
    //
    // Contrat :
    //

    int Charge(string cheminAcces,CritereSelection critere);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AddTrajetSimple();
    // Mode d'emploi :
    // Méthode qui permet de créer un trajet simple et qui l'ajoute à l'attribut listeTrajets
    // On demande une ville de départ et d'arrivée ainsi qu'un moyen de transport.
    // Contrat :
    //

    void AddTrajetCompose();
    // Mode d'emploi :
    //Permet de créer un trajet composé, à partir de plusieurs trajets simples. On ajoute
    // ensuite ce trajet à l'attribut listeTrajets.
    // On demande d'abord le nombre de sous trajet, et une ville de départ, d'arrivée et un moyen
    // de transport pour chaque sous trajet.
    // Contrat :
    //  La ville de départ du premier sous trajet, ainsi que la ville d'arrivée du dernier sous trajet
    // doivent être la même que la ville de départ et d'arrivée Générale.
    // la ville de départ d'un sous trajet doit être la même que la ville d'arrivée du sous trajet précédent.

    void RechercheSimple();
    // Mode d'emploi :
    // Permet de faire une recherche parmis les trajets existant. On entre une ville de départ et d'arrivée, et la méthode
    // affiche alors les trajets (simples et composés) correspondants, s'ils existent.
    // Contrat :
    //  Les noms des villes doivent correspondre exactement à ceux déjà rentrés, au caractère et à la majuscule près

    void RechercheComplexe();
    // Mode d'emploi :
    //  pour un voyage donné, défini par une ville  de départ et d’arrivée, permet retrouver
    //  dans la liste de trajet existante tous les parcours permettant de réaliser ce voyage.
    // Ce voyage peut alors se composer de plusieurs trajets qui s'enchainent.
    // Contrat :
    //  Les noms des villes doivent correspondre exactement à ceux déjà rentrés, au caractère et à la majuscule près

//------------------------------------------------- Surcharge d'opérateurs

    friend ostream & operator << (ostream & flux, const Catalogue & unCatalogue);

//-------------------------------------------- Constructeurs - destructeur

    Catalogue ();
    // Mode d'emploi :
    // Constrcteur de la classe, permet de créer un catalogue composé d'une liste de
    // trajets
    // Contrat :
    //

    virtual ~Catalogue ();
    // Mode d'emploi :
    // Destructeur de la classe
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    string & createBuffer(string & buffer, Trajet* traj);
    // Mode d'emploi :
    // Affiche un message dans la console demandant à l'utilisateur de saisir une ville
    // d'arrivée, et renvoie la saisie de l'utilisateur à l'aide d'un pointeur
    // Contrat :
    //

    Trajet* construitTrajetAvecLecture(ifstream & fichier);
    // Mode d'emploi :
    //
    // Contrat :
    // Il faut que le fichier soit correctement ouvert (vérification en amont)

    char * askVilleArrivee();
    // Mode d'emploi :
    // Affiche un message dans la console demandant à l'utilisateur de saisir une ville
    // d'arrivée, et renvoie la saisie de l'utilisateur à l'aide d'un pointeur
    // Contrat :
    //

    char * askVilleDepart();
    // Mode d'emploi :
    // Affiche un message dans la console demandant à l'utilisateur de saisir une ville
    // de départ, et renvoie la saisie de l'utilisateur à l'aide d'un pointeur
    // Contrat :
    //

    char * askMoyenTransport();
    // Mode d'emploi :
    // Affiche un message dans la console demandant à l'utilisateur de saisir un moyen
    // de transport, et renvoie la saisie de l'utilisateur à l'aide d'un pointeur
    // Contrat :
    //

    int rechercheEtape(const char * departTrajet, const char * arriveeFinale, ListeTrajets trajetsPossibles);
    // Mode d'emploi :
    // Méthode initialement appelée par rechercheComplexe, puis appelée récursivement,  permettant d'effectuer la recherche complexe. On demande en paramètre
    // la ville de départ du trajet actuellement étudié (à l'étape n), la destination finale, ainsi qu'une liste de trajets Contenant
    // les trajets déjà parcouru permettant d'arriver à l'étape n
    // on renvoie ensuite le nombre de possibilités permettant de relier la ville de départ initale à la destination finale. Un affichage de la liste des trajets
    // parcourus est effectué quand on a atteint la destination finale
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés

    ListeTrajets listeTraj;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
