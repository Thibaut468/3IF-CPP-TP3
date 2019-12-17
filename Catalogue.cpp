/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

static const int TAILLE_ENTREE_VILLE = 45;
static const int TAILLE_ENTREE_MOYEN_TRANSPORT = 20;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::AddTrajetSimple()
// Algorithme :
// On demande à l'utilisateur les villes de départ , d'arrivée et le moyen de transport
// à l'aide des trois méthodes ask... et on crée ensuite un trajet Simple que l'on ajoute
// dans l'attribut listTraj (qui est une liste de trajets)
{
    char * vDepart = askVilleDepart();
    char * vArrivee = askVilleArrivee();
    char * vMoyenTransport = askMoyenTransport();
    TrajetSimple * nouveauTrajet = new TrajetSimple(vDepart,vArrivee,vMoyenTransport);
    listeTraj.AddTrajet(nouveauTrajet);
    delete [] vDepart;
    delete [] vArrivee;
    delete [] vMoyenTransport;
} //----- Fin de addTrajetSimple

void Catalogue::AddTrajetCompose()
// Algorithme :
// On demande à l'utilisateur les villes de départ et d'arrivée globales du trajet, ainsi que
// le nombre de sous trajets.
// On s'assure que les entrées sont correctes à l'aide de While, et on demande de les resaisir tant qu'elles
// ne le sont pas.
// on crée des variables temporaire à chaque nouvelle étape,  pour stocker les villes et le moyen de transport, que l'on
// détruit une fois les trajets crées.
{
    int nbTrajets;
    ListeTrajets* liste=new ListeTrajets();
    cout<<"Nombre de trajets ?"<<endl;
    cin >> nbTrajets;
    cin.ignore();
    while(cin.fail())
    {
        cout << "Erreur, veuillez entrer un entier" <<endl;
        cin.clear();          //on clear les erreurs
        cin.ignore();         // on ignore le prochain caractère
        cin >> nbTrajets;             //on redemande la valeur;
        cin.ignore();
    }

    char vDepartPrincipale[TAILLE_ENTREE_VILLE+1];
    char vArriveePrincipale[TAILLE_ENTREE_VILLE+1];
    char vArriveePrecedent[TAILLE_ENTREE_VILLE+1];

    char * vDepart = askVilleDepart();
    char * vArrivee = askVilleArrivee();
    char * mTransport = askMoyenTransport();

    TrajetSimple* tmpTrajet=new TrajetSimple(vDepart,vArrivee,mTransport);

    liste->AddTrajet(tmpTrajet);
    strcpy(vArriveePrecedent,vArrivee);
    strcpy(vDepartPrincipale,vDepart);

    for(int i=1;i<nbTrajets;i++)
    {
        delete [] vArrivee;
        delete [] vDepart;
        delete [] mTransport;
        vDepart = askVilleDepart();
        vArrivee = askVilleArrivee();
        mTransport = askMoyenTransport();

        if(strcmp(vDepart,vArriveePrecedent)==0)
        {
            TrajetSimple* tmpTrajet=new TrajetSimple(vDepart,vArrivee,mTransport);
            liste->AddTrajet(tmpTrajet);
            strcpy(vArriveePrecedent,vArrivee);
        }
        else
        {
            while(strcmp(vDepart,vArriveePrecedent)!=0)
            {
                cout << "Erreur, vous devez repartir de la ville d'étape précédente" <<endl;
                delete [] vArrivee;
                delete [] vDepart;
                delete [] mTransport;
                vDepart = askVilleDepart();
                vArrivee = askVilleArrivee();
                mTransport = askMoyenTransport();
            }

            TrajetSimple* tmpTrajet=new TrajetSimple(vDepart,vArrivee,mTransport);
            liste->AddTrajet(tmpTrajet);
            strcpy(vArriveePrecedent,vArrivee);
        }
    }

    strcpy(vArriveePrincipale,vArrivee);

    TrajetCompose* nouveauTrajetCompose=new TrajetCompose(vDepartPrincipale,vArriveePrincipale,liste);
    listeTraj.AddTrajet(nouveauTrajetCompose);

    delete [] vArrivee;
    delete [] vDepart;
    delete [] mTransport;
} //----- Fin de AddTrajetCompose



void Catalogue::RechercheSimple()
// Algorithme :
// On récupère la liste de trajets en attribut sous la forme d'un Tableau dynamique de trajets.
// On parcours ensuite ce tableau en recherchant les trajets existant pours lesquels les villes de départ
// et d'arrivée correspondent à celles entrées par l'utilisateur. Si ces trajets existent, on appelle leur méthode
// Affichage
//
{
    char * vDepart=askVilleDepart();
    char * vArrivee=askVilleArrivee();
    bool trouve = false;
    int cpt = 0;

    cout << endl << "-- Résultat de la recherche simple entre " << vDepart << " et " << vArrivee << " --" << endl << endl;

    Trajet ** listeTmp = listeTraj.GetListe();
    int nbTrajets = listeTraj.GetNbTrajets();
    for(int i=0;i<nbTrajets;i++)
    {
        if(strcmp(listeTmp[i]->GetVilleDepart(),vDepart)==0 && strcmp(listeTmp[i]->GetVilleArrivee(),vArrivee)==0)
        {
            listeTmp[i]->Affichage();
            trouve=true;
            ++cpt;
            cout << endl;
        }
    }

    if(!trouve)
    {
        cout << "            AUCUN TRAJET DISPONIBLE" << endl << endl;
    }

    cout << "           Nombre de trajets trouvés : " << cpt << endl;
    cout << "-----------------------------------------------------------" << endl;

    delete [] vDepart;
    delete [] vArrivee;
} //----- Fin de RechercheSimple


void Catalogue::RechercheComplexe()
// Algorithme :
// On crée une liste de trajet vide et on demande à l'utilisateur de saisir la ville de départ initale et la destination finale.
// On appelle ensuite la méthode rechercheEtape avec ces trois paramètres.
// La méthode rechercheEtape retourne alors le nombre de trajets trouvés, que l'on affiche. L'affichage de ces trajets est gérée par RechercheEtape
{
    char * vDepart=askVilleDepart();
    char * vArrivee=askVilleArrivee();
    ListeTrajets trajetsPossibles = ListeTrajets();

    cout << endl << "-- Résultat de la recherche complexe entre " << vDepart << " et " << vArrivee << " --" << endl << endl ;

    int nb = rechercheEtape(vDepart,vArrivee,trajetsPossibles);

    if(nb==0)
    {
        cout << "            AUCUN TRAJET DISPONIBLE" << endl;
    }

    cout << "---- Fin de la recherche complexe : " << nb << " ont étés proposées ----" << endl;

    delete [] vDepart;
    delete [] vArrivee;
} //----- Fin de RechercheComplexe



//------------------------------------------------- Surcharge d'opérateurs

ostream & operator << (ostream & flux, const Catalogue & unCatalogue)
// Algorithme :
// Parcours l'attribut ListeTraj pou afficher les trajets présents dans le catalogue.
// Pour simplifier le parcours, on vient récupérer la liste de trajets sous la forme d'un
// tableau dynamique.
{
    int nbTrajets = unCatalogue.listeTraj.GetNbTrajets();
    cout << nbTrajets << endl;
    if(nbTrajets==0)
    {
        cout << "---------- CATALOGUE VIDE ----------" << endl;
    }
    else
    {
        Trajet ** traj = unCatalogue.listeTraj.GetListe();
        cout << "---------- CONTENU DU CATALOGUE ----------" << endl;
        cout << endl;
        for(int i=0; i<nbTrajets;i++)
        {
            traj[i]->Affichage();
            cout << endl;
        }

        cout << "-------------------------------------------" << endl;
    }
} //----- Fin de surcharge opérateur <<




//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue () : listeTraj()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
// On parcours toute la liste listeTraj afin de détruire chacun des trajets présents.
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    for(int i=0;i<listeTraj.GetNbTrajets();i++)
    {
        delete listeTraj.GetListe()[i];
    }
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

char * Catalogue::askVilleArrivee()
// Algorithme :
//
{
    char* ret=new char[TAILLE_ENTREE_VILLE+1];
    cout << "Saisir la ville d'arrivée: " << endl;
    cin.getline(ret,TAILLE_ENTREE_VILLE);
    return ret;
} //----- Fin de AskVilleDepart

char * Catalogue::askVilleDepart()
// Algorithme :
//
{
    char* ret = new char[TAILLE_ENTREE_VILLE+1];
    cout << "Saisir la ville de départ : " << endl;
    cin.getline(ret,TAILLE_ENTREE_VILLE);
    return ret;
} //----- Fin de AskVilleArrivee

char * Catalogue::askMoyenTransport()
// Algorithme :
//
{
    char* ret=new char[TAILLE_ENTREE_MOYEN_TRANSPORT+1];
    cout << "Saisir le moyen de transport : " << endl;
    cin.getline(ret,TAILLE_ENTREE_VILLE);
    return ret;
} //----- Fin de AskMoyenTransport

int Catalogue::rechercheEtape(const char * departTrajet, const char * arriveeFinale, ListeTrajets trajetsPossibles)
//Algorithme : Methode recursive
// departTrajet représente la ville actuellement étudiée, arrivéeFinale représente la ville de destination finale, et trajetsPossibles contient tous les trajets qui ont déjà été parcourus
// permettant d'arriver à la ville actuellement étudiée (departTrajet).
// Cette méthode est récursive. On parcours la liste des trajets présent dans Catalogue, et pour chacun de ces trajets T, si la ville de départ correspond à départTrajet, on réapelle cette méthode en
// Ajoutant le trajet T à la liste trajetsPossibles, et en passant la ville d'arrivée du trajet T dans départTrajet. cette ville devient alors la prochaine étape etudiée.
//
// Si la ville actuellement étudiée est la même que l'arriveeFinale: On a notre condition d'arrêt. Dans ce cas la liste trajetsPossibles contient une liste de trajets permettant de relier la ville
// Initiale à la destination Finale: On affiche alors ces trajets et on retourne 1 (le retour représente le nombre de trajets différents trouvés)
// Soit on a parcouru toute la liste de Trajets listeTraj sans trouver de nouveau trajet partant de departTrajet. Dans ce cas on
{
    int condition;
    int compteurTrajets = 0;

    if(strcmp(departTrajet,arriveeFinale)==0) // si ville de départ et d'arrivee sont les mêmes: signifie qu'on à atteint notre destination
    {

        for(int i = 0;i<trajetsPossibles.GetNbTrajets();i++)
        {
            trajetsPossibles.GetListe()[i]->Affichage();
        }

        cout << endl;

        return 1;
    }

    for(int i=0;i<listeTraj.GetNbTrajets();i++)
    {
        Trajet* t=listeTraj.GetListe()[i];

        if(strcmp(t->GetVilleDepart(),departTrajet)==0) //si le trajet t auquel on s'intéresse part bien du même point que le noeud ou l'on est actuellement
        {
            condition=1;

            for(int j=0;j<trajetsPossibles.GetNbTrajets();j++)
            {
                if (strcmp(t->GetVilleArrivee(), trajetsPossibles.GetListe()[j]->GetVilleDepart()) ==0) //si la ville d'arrivée est déja présente dans les trajets possible en tant que ville de départ
                {
                    condition = 0;        //afin de ne pas créer de boucle infini
                }
            }
            if(condition)
            {
                trajetsPossibles.AddTrajet(t);                                       //On ajoute une arrête à explorer à partir de ce noeud
                compteurTrajets+=rechercheEtape(t->GetVilleArrivee(),arriveeFinale,trajetsPossibles);  //On part explorer cette arrête
                trajetsPossibles.RetirerDernier();                                   //On retire cette arrête pour ne pas l'explorer à partir des autres noeuds
            }
        }
    }

    return compteurTrajets;
}// Fin de RechercheEtape


//----------------------------------------------------- Méthodes protégées
