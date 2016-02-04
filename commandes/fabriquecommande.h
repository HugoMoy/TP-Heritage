#ifndef FABRIQUECOMMANDE_H
#define FABRIQUECOMMANDE_H

#include <map>
#include <vector>
#include "../modele/forme.h"

class Commande;

class FabriqueCommande
{
private:
	Commande * listeCommande[20];
	Commande * listeUndo[20];
	map<string, ptr_Forme> listeForme;
	vector<Commande*> historiqueCommande;

	int indexCommande;
	int indexUndo;

public:
    FabriqueCommande();
	~FabriqueCommande();

	bool executerCommande(string commande);

	bool ajouterForme(ptr_Forme forme);
	bool retirerForme(ptr_Forme forme);
	bool retirerForme(string nom);

	const map<string, ptr_Forme> getFormes(){return listeForme;}
	ptr_Forme find(string nom);

private:
	void ajouterCommande(Commande * commande);
	
};

#endif // FABRIQUECOMMANDE_H
