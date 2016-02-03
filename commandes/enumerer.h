#ifndef ENUMERER_H
#define ENUMERER_H

#include "commande.h"

class Enumerer : public Commande
{
public:
    Enumerer(FabriqueCommande * fCommande);

	bool exec();
	bool unexec();
};

#endif // ENUMERER_H
