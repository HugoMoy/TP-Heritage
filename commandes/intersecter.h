#ifndef INTERSECTER_H
#define INTERSECTER_H

#include "commande.h"
#include "../modele/intersection.h"
#include <string>

class Intersecter : Commande
{
private:
	string * formesNom;
	int nbFormes;
	string nom;
	ptr_Forme * formes;

	Intersection * intersection;

public:
	

    Intersecter(string name, string formesName[], int nbFormes, FabriqueCommande * fCommande);

	bool exec();
	bool unexec();

};

#endif // INTERSECTER_H
