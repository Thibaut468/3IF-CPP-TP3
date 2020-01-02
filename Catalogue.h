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
// des trajets simples et complexes, et enfin une méthode permettant d'afficher les trajets existants.
//
// Elle possède aussi une méthode permettant de sauvegarder ses trajets dans un fichier externe et une autre
// pour les restituer. Il existe alors différentes méthodes protégées pour interagir avec l'utilisateur et d'autres
// pour fonctionner comme un filtre sur les trajets, permettant de savoir s'il faut ou non les sauvegarder/restituer
// en fonction de critères de sélections.
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
    // Permet de créer un trajet composé, à partir de plusieurs trajets simples. On ajoute
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
    // pour un voyage donné, défini par une ville  de départ et d’arrivée, permet retrouver
    // dans la liste de trajet existante tous les parcours permettant de réaliser ce voyage.
    // Ce voyage peut alors se composer de plusieurs trajets qui s'enchainent.
    // Contrat :
    // Les noms des villes doivent correspondre exactement à ceux déjà rentrés, au caractère et à la majuscule près

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

    bool respectCriteria(Trajet * trajet, CritereSelection critere, string param1, string param2, int param3);
    // Mode d'emploi
    // Pour le trajet pointé par le pointeur passé en paramètre, renvoi vrai s'il respecte critere (en se servant
    // des paramètres1 et 2 si besoin). Renvoi faux sinon.
    // Permet de filtrer les trajets.
    //
    // Pour les paramètres :
    //  Critère SANS : param1 --> / - param2 --> / - param3 --> /
    //  Critère TYPE : param1 --> TS ou TC - param2 --> / - param3 --> /
    //  Critère VILLE : param1 --> vDepart - param2 --> vArrivee - param3 --> /
    //  Critère TRAJETS cad entre [n,m] : param1 --> n - param2 --> m - param3 --> numero du trajet dans la liste
    //
    // Contrat :
    // Les paramètres correspondent bien au critère demandé.

    void askParameters(CritereSelection critere, string & param1, string & param2);
    // Mode d'emploi
    // Rempli les parametres 1, 2 et 3 en fonction du critere selectionné. Voir la mode d'emploi de la méthode au
    // desssus (respectCriteria) pour comprendre leur utilité.
    // Contrat :
    //

    int putInFile(ostream & stream, int & counter, ostringstream & buffer);
    // Mode d'emploi ;
    // Insère dans le stream passé en parametre le buffer.
    // Incrémente aussi le counter de 1, signifiant l'ajout d'une ligne.
    // Renvoi 0 si tout s'est bien passé, -1 sinon
    // Contrat :
    // Le stream de sortie doit être au préalable correctement ouvert

    ostringstream & createBuffer(ostringstream & buffer, Trajet* traj);
    // Mode d'emploi :
    // Rempli le buffer d'entrée avec les caractéristique du trajet pointé par le pointeur passé en paramètre.
    // Il respecte le "template" expliqué dans le compte rendu pour la création du buffer.
    // Renvoi le buffer rempli si tout s'est bien passé, un buffer vide sinon.
    // Contrat :
    // Le pointeur de trajet passé en paramètre n'est pas le pointeur null.

    Trajet* construitTrajetAvecLecture(ifstream & fichier);
    // Mode d'emploi :
    // Instancie de façon dynamique un trajet correspondant à la prochaine ligne disponible dans le file stream passé
    // en paramètre.
    // Contrat :
    // Il faut que le fichier soit correctement ouvert (vérification en amont)
    // Il faut que la syntaxe respecte la "template" décrite dans notre compte rendu.

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
