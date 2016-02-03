#include "enumerer.h"

Enumerer::Enumerer(FabriqueCommande * fCommande) : Commande(fCommande)
{
}


bool Enumerer::exec()
{
	commandeFactory->enumere();
	return true;
}

bool Enumerer::unexec()
{
	return true;
}