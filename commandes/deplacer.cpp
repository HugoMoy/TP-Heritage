#include "deplacer.h"

Deplacer::Deplacer(int x, int y, string nom, FabriqueCommande * fCommande) : Commande(fCommande)
{
	dx = x;
	dy = y;
	nomForme = nom;
}

bool Deplacer::exec()
{
	forme = commandeFactory->find(nomForme);
	if(forme == nullptr)
		return false;
	forme->deplacer(dx, dy);
	return true;
}

bool Deplacer::unexec()
{
	if(forme == nullptr)
		return false;
	forme->deplacer(-dx,-dy);
	return true;
}

string Deplacer::saveLine()
{
	string chaine = "MOVE ";
	chaine += nomForme + " ";
	chaine += dx + " ";
	chaine += dy;

	return chaine;
}