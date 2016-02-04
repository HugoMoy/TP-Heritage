#include "supprimer.h"

Supprimer::Supprimer(string nomFormes[], int nb, FabriqueCommande * fCommande) : Commande(fCommande)
{
	noms = nomFormes;
	nbFormes = nb;
	forme = new ptr_Forme[nb];
}

Supprimer::~Supprimer()
{
	for(int i =0; i<nbFormes; i++)
		delete forme[i];
}

bool Supprimer::exec()
{
	for(int i = 0; i < nbFormes; i ++)
	{
	forme[i] = commandeFactory->find(noms[i])->clone();
	if(forme == nullptr)
		return false;
	commandeFactory->retirerForme(noms[i]);
	}
	return true;
}

bool Supprimer::unexec()
{
	for (int i =0; i<nbFormes; i++)
	{
		commandeFactory->ajouterForme(forme[i]);
	}
	return true;
}

string Supprimer::saveLine()
{
	string chaine = "DELETE";
	for(int i =0; i < nbFormes; i++)
	{
		chaine += " " + noms[i];
	}

	return chaine;
}