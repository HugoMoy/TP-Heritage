#ifndef COMMANDE_H
#define COMMANDE_H

#include "fabriquecommande.h"

class Commande
{
protected:
	FabriqueCommande * commandeFactory;

public:
    Commande(FabriqueCommande * fCommande);
	virtual ~Commande();

	virtual bool exec()=0;
	virtual bool unexec()=0;
	virtual string saveLine()=0;
};

#endif // COMMANDE_H
