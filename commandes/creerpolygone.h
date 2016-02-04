#ifndef CREERPOLYGONE_H
#define CREERPOLYGONE_H

#include <string>
#include "commande.h"
#include "../modele/polygone.h"

using namespace std;

class CreerPolygone : public Commande
{
private:
	pair<int,int> * points;
	int nbPoints;
	string nom;
	Polygone * poly;

public:
	

    CreerPolygone(int mPoints[], int mnbPoints, string name, FabriqueCommande * fCommande);
	~CreerPolygone();

	bool exec();
	bool unexec();
	string saveLine();
};

#endif // CREERPOLYGONE_H
