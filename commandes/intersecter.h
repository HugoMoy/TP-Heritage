#ifndef INTERSECTER_H
#define INTERSECTER_H

#include "commande.h"
#include "../modele/intersection.h"
#include <string>

class Intersecter : public Commande
{
private:
	string * formesNom;
	int nbFormes;
	string nom;
	ptr_Forme * formes;

	Intersection * intersection;

public:
	

    Intersecter(string name, string formesName[], int nbFormes, FabriqueCommande * fCommande);
	~Intersecter();

	bool exec();
	bool unexec();
	string saveLine();

};

#endif // INTERSECTER_H
