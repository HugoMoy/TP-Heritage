#ifndef APPARTIENT_H
#define APPARTIENT_H

#include "commande.h"
#include "../modele/forme.h"
#include <string>

class Appartient : public Commande
{
	int x, y;
	string nomForme;
	ptr_Forme forme;

public:
    Appartient(int pX, int pY, string nom, FabriqueCommande * fCommande);

	bool exec();
	bool unexec();
};

#endif // APPARTIENT_H
