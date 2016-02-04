#include "vider.h"

Vider::Vider(FabriqueCommande * fCommande) : Commande(fCommande)
{
	formes = commandeFactory->getFormes();

	for(map<string, ptr_Forme>::iterator i = formes.begin(); i!=formes.end();i++)
	{
		i->second = i->second->clone();
	}

}

Vider::~Vider()
{
	for(map<string, ptr_Forme>::iterator i = formes.begin(); i!=formes.end();i++)
	{
		delete i->second;
	}
}

bool Vider::exec()
{
	for(map<string, ptr_Forme>::iterator i = formes.begin(); i!=formes.end();i++)
	{
		if(!commandeFactory->retirerForme(i->second))
			return false;
	}
	return true;
}

bool Vider::unexec()
{
	for(map<string, ptr_Forme>::iterator i = formes.begin(); i!=formes.end();i++)
	{
		if(!commandeFactory->ajouterForme(i->second))
			return false;
	}
	return true;
}

string Vider::saveLine()
{
	return "CLEAR";
}