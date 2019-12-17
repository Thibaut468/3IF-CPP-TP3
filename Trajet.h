/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 19 NOVEMBRE
    copyright            : (C) 2019 par BRANCHEREAU,GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>

// Trajet est un objet, qui représente un trajet d'une ville A vers une ville B
// ELle comporte deux attributs (des chaines de caractères): la ville de départ
// et la ville d'arrivée
// On met en place un héritage: cette classe est la classe "mère", et on
// retrouve deux classes filles qui en hérite: TrajetSimple et TrajetCompose
// C'est une classe abstraite car ces constructeurs ont été mis en protégés.
// De cette façon, elle devient non instanciable.
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Affichage () const;
    // Mode d'emploi :
    // Ecrit dans la console la ville de départ et la ville d'arrivée
    //Cette méthode est virtuelle: si l'objet qui l'appelle est de type fille,
    // on appelle l'affichage de la classe fille
    // Contrat :
    //

    char* GetVilleDepart() const;
    // Mode d'emploi :
    // Un getteur qui permet d'obtenir l'attribut villeDepart
    // Contrat :
    //

    char* GetVilleArrivee() const;
    // Mode d'emploi :
    // Un getteur qui permet d'obtenir l'attribut villeArrivee
    // Contrat :
    //

    virtual string GetType() const = 0;
    // Mode d'emploi :
    // Un getteur qui permet d'obtenir le type de trajet (simple ou composée)
    // C'est une méthode virtuelle pure devant être redéfinie chez les descendants
    // Contrat :
    //

    //-------------------------------------------- Destructeur

    virtual ~Trajet ( );
    // Mode d'emploi :
    // Destructeur de la classe: supprime les villeDepart et villeArrivee de
    // la mémoire
    // méthode virtuelle: s
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //-------------------------------------------- Constructeurs

    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi :
    // Constructeur de copie de la classe: crée un nouveau Trajet à partir d'un
    // Trajet déjà existant: affecte les mêmes villes de départ et d'arrivée
    // Contrat :
    //

    Trajet (const char* vDepart,const char* vArrivee);
    // Mode d'emploi :
    //  Constructeur de la classe: affecte les valeurs des attributs villes de
    //départ et d'arrivée
    // Contrat :
    //


    //----------------------------------------------------- Attributs protégés
    char* villeDepart;
    char* villeArrivee;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
