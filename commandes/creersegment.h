#ifndef CREERSEGMENT_H
#define CREERSEGMENT_H

#include "commande.h"
#include <string>
#include "../modele/segment.h"

class CreerSegment : public Commande
{
private:
	int x1, x2, y1, y2;
	string nom;
	Segment * segment;

public:
    CreerSegment(string name, int mX1, int mY1, int mX2, int mY2,  FabriqueCommande * fCommande);

	bool exec();
	bool unexec();
};

#endif // CREERSEGMENT_H
