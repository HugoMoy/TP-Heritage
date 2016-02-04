#include "unir.h"

Unir::Unir(string name, string formesName[], int nb, FabriqueCommande * fCommande) : Commande(fCommande)
{
	nom = name;
	formesNom = formesName;
	nbFormes = nb;
	formes = new ptr_Forme[nb];
}

Unir::~Unir()
{
	delete uni;
}

bool Unir::exec()
{
	for(int i = 0; i<nbFormes; i++)
	{
		Forme * uneForme = commandeFactory->find(formesNom[i]);
		if(uneForme == nullptr)
		{
			return false;
		}

		formes[i] = uneForme->clone();

	}

	uni = new Union(nom, formes, nbFormes);
	return commandeFactory->ajouterForme(uni);
}

bool Unir::unexec()
{
	return commandeFactory->retirerForme(uni);
}

string Unir::saveLine()
{
	string chaine = "OR ";
	chaine += nom;

	for (int i = 0; i < nbFormes; i++)
	{
		chaine += " " + formes[i]->getNom();
	}

	return chaine;
}