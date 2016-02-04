#include "commande.h"

Commande::Commande(FabriqueCommande * fCommande)
{
	commandeFactory = fCommande;
}

Commande::~Commande()
{

}