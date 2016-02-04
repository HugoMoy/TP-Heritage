#ifndef SUPPRIMER_H
#define SUPPRIMER_H

#include "commande.h"
#include "../modele/forme.h"
#include <string>

class Supprimer : public Commande
{
private:
	string * noms;
	int nbFormes;
	ptr_Forme * forme;

public:
    Supprimer(string nomForme[], int nb, FabriqueCommande * fCommande);
	~Supprimer();

	bool exec();
	bool unexec();
	string saveLine();
};

#endif // SUPPRIMER_H
