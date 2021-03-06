#include "intersecter.h"

Intersecter::Intersecter(string name, string formesName[], int nb, FabriqueCommande * fCommande) : Commande(fCommande)
{
	nom = name;
	formesNom = formesName;
	nbFormes = nb;
	formes = new ptr_Forme[nb];
}

Intersecter::~Intersecter()
{
	delete intersection;
}

bool Intersecter::exec()
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

	intersection = new Intersection(nom, formes, nbFormes);
	return commandeFactory->ajouterForme(intersection);
}

bool Intersecter::unexec()
{
	return commandeFactory->retirerForme(intersection);
}

string Intersecter::saveLine()
{
	string chaine = "OI ";
	chaine += nom;

	for (int i = 0; i < nbFormes; i++)
	{
		chaine += " " + formes[i]->getNom();
	}

	return chaine;
}