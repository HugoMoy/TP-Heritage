#ifndef UNIR_H
#define UNIR_H

#include "commande.h"
#include "../modele/union.h"
#include <string>

class Unir : public Commande
{
private:
	string * formesNom;
	int nbFormes;
	string nom;
	ptr_Forme * formes;

	Union * uni;

public:
	

    Unir(string name, string formesName[], int nbFormes, FabriqueCommande * fCommande);
	~Unir();

	bool exec();
	bool unexec();
	string saveLine();

};

#endif // UNIR_H
