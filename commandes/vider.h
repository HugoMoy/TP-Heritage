#ifndef VIDER_H
#define VIDER_H

#include "commande.h"
#include <string>
#include "../modele/forme.h"

class Vider : public Commande
{
private :
	map<string, ptr_Forme> formes;

public:
    Vider(FabriqueCommande * fCommande);

	bool exec();
	bool unexec();
};

#endif // VIDER_H
