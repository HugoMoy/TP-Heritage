#include "creerrectangle.h"

CreerRectangle::CreerRectangle(int mPoints[], string name, FabriqueCommande * fCommande) : Commande(fCommande)
{
	coordonnees[0] = mPoints[0];
	coordonnees[1] = mPoints[1];
	coordonnees[2] = mPoints[2];
	coordonnees[3] = mPoints[3];

	nom = name;
}

bool CreerRectangle::exec()
{
	if(coordonnees[0] > coordonnees[2] || coordonnees[1] > coordonnees[3])
		return false;

	rectangle = new Rectangle(nom, coordonnees[0],coordonnees[1], coordonnees[2], coordonnees[3]);
	return commandeFactory->ajouterForme(rectangle);
}

bool CreerRectangle::unexec()
{
	return commandeFactory->retirerForme(rectangle);
}
