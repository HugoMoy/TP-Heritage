#include "appartient.h"

Appartient::Appartient(int pX, int pY, string nom, FabriqueCommande * fCommande) : Commande(fCommande)
{
	x = pX;
	y = pY;
	nomForme = nom;
}

bool Appartient::exec()
{
	forme = commandeFactory->find(nomForme);
	if(forme == nullptr)
		return false;
	pair<int, int> point = pair<int,int>(x,y);
	forme->contient(point);
	return true;
}

bool Appartient::unexec()
{
	return true;
}