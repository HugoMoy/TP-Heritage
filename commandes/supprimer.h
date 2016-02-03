#ifndef SUPPRIMER_H
#define SUPPRIMER_H

#include "commande.h"
#include "../modele/forme.h"
#include <string>

class Supprimer : public Commande
{
private:
	string nom;
	ptr_Forme forme;

public:
    Supprimer(string nomForme, FabriqueCommande * fCommande);

	bool exec();
	bool unexec();
};

#endif // SUPPRIMER_H
