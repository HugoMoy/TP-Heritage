#ifndef CREERRECTANGLE_H
#define CREERRECTANGLE_H

#include "commande.h"
#include "../modele/rectangle.h"
#include <utility>
#include <string>

class CreerRectangle : public Commande
{
public:
 private:
	int coordonnees[4];
	string nom;
	Rectangle * rectangle;

public:
	

    CreerRectangle(int mPoints[], string name, FabriqueCommande * fCommande);


	bool exec();
	bool unexec();
};

#endif // CREERRECTANGLE_H
