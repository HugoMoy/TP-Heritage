#include "creersegment.h"

CreerSegment::CreerSegment(string name, int mX1, int mY1, int mX2, int mY2,  FabriqueCommande * fCommande) : Commande(fCommande)
{
	nom = name;
	x1 = mX1;
	x2 = mX2;
	y1 = mY1;
	y2 = mY2;
}

bool CreerSegment::exec()
{
	segment = new Segment(nom, x1, y1, x2, y2);
	return commandeFactory->ajouterForme(segment);
}

bool CreerSegment::unexec()
{
	return commandeFactory->retirerForme(segment);
}
