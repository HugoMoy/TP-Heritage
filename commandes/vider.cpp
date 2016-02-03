#include "vider.h"

Vider::Vider(FabriqueCommande * fCommande) : Commande(fCommande)
{
	formes = commandeFactory->getFormes();
}

bool Vider::exec()
{
	for(map<string, ptr_Forme>::iterator i = formes.begin(); i!=formes.end();i++)
	{
		commandeFactory->retirerForme(i->second);
	}
	return true;
}

bool Vider::unexec()
{
	for(map<string, ptr_Forme>::iterator i = formes.begin(); i!=formes.end();i++)
	{
		commandeFactory->ajouterForme(i->second);
	}
	return true;
}

