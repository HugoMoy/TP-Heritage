#include "quitter.h"

Quitter::Quitter(FabriqueCommande * fCommande) : Commande(fCommande)
{

}

bool Quitter::exec()
{
	return true;
}

bool Quitter::unexec()
{
	return true;
}