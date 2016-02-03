#include "supprimer.h"

Supprimer::Supprimer(string nomForme, FabriqueCommande * fCommande) : Commande(fCommande)
{
	nom = nomForme;
	
}

bool Supprimer::exec()
{
	forme = commandeFactory->find(nom);
	if(forme == nullptr)
		return false;
	
	return commandeFactory->retirerForme(nom);
}

bool Supprimer::unexec()
{
	return commandeFactory->ajouterForme(forme);
}
