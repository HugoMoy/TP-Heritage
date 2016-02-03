#ifndef QUITTER_H
#define QUITTER_H

#include "commande.h"

class Quitter : public Commande
{
public:
    Quitter(FabriqueCommande * fCommande);

	bool exec();
	bool unexec();
};

#endif // QUITTER_H
