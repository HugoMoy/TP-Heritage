#ifndef FABRIQUECOMMANDE_H
#define FABRIQUECOMMANDE_H

#include <map>

class FabriqueCommande
{
private:
	Commande * listeCommande[20];
	Commande * listeUndo[20];
	map<string, Forme*> listeForme;

	int indexCommande;
	int indexUndo;

public:
    FabriqueCommande();

	bool ajouterForme(Forme * forme);
	bool retirerForme(Forme * forme);
	bool retirerForme(string nom);
	Forme* find(string nom);
};

#endif // FABRIQUECOMMANDE_H
