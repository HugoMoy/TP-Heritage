#include "creerpolygone.h"

CreerPolygone::CreerPolygone(int mPoints[], int mnbPoints, string name, FabriqueCommande * fCommande) : Commande(fCommande)
{
	points = new pair<int, int>[mnbPoints/2];
	for(int i = 0; 2*i <mnbPoints;i++)
	{
		points[i] = pair<int,int>(mPoints[2*i],mPoints[2*i+1]);
	}
	nbPoints = mnbPoints;
	nom = name;

}

CreerPolygone::~CreerPolygone()
{
	delete poly;
}

bool CreerPolygone::exec()
{
	if(nbPoints%2 == 1)
	{
    		return false;
    	}
    	nbPoints = nbPoints/2;
	poly = new Polygone(nom, nbPoints);
	for(int i = 0; i < nbPoints; i++)
	{
		if(!poly->ajouterPoint(points[i].first, points[i].second))
			return false;
	}	
	return commandeFactory->ajouterForme(poly);
}

bool CreerPolygone::unexec()
{
	return commandeFactory->retirerForme(poly);
}

string CreerPolygone::saveLine()
{
	string chaine = "PC ";
	chaine += nom;
	for (int i = 0; i < nbPoints; i++)
	{
		chaine += " " + to_string(points[i].first);
		chaine += " " + to_string(points[i].second);
	}

	return chaine;
}
