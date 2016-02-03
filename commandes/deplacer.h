#ifndef DEPLACER_H
#define DEPLACER_H

#include "commande.h"
#include "../modele/forme.h"
#include <string>

class Deplacer : public Commande
{
private:
	int dx, dy;
	string nomForme;
	ptr_Forme forme;

public:
    Deplacer(int x, int y, string nom, FabriqueCommande * fCommande);

	bool exec();
	bool unexec();
};

#endif // DEPLACER_H
