#include "polygone.h"
#include <math.h>

Polygone::Polygone(string name, int nb) : Forme(name)
{
    sommet = 0;
    nbPoints = nb;
    listePoints = new pair<int, int>[nb];
}

Polygone::~Polygone()
{
    delete[] listePoints;
}

bool Polygone::ajouterPoint(int x, int y)
{
    if(sommet <= 3)
    {
   listePoints[sommet] = pair<int,int>(x,y);
   sommet++;
    }

	else if(sommet < nbPoints)
	{
		pair<int, int> nouveauSommet(x,y);
		if(anglePositif(listePoints[sommet-2], listePoints[sommet-1], listePoints[sommet]) == anglePositif(listePoints[sommet], listePoints[sommet], nouveauSommet))
		{
			listePoints[sommet] = nouveauSommet;
			sommet++;
		}
	}
}

bool Polygone::contient(std::pair<int, int> point)
{
    pair<int,int> pointDeDepart = listePoints[0];
    pair<int,int> pointDeDepart2 = listePoints[nbPoints-1];
    bool premierAnglePositif = anglePositif(pointDeDepart,point, pointDeDepart2);


    for(int i =1; i < nbPoints; i++)
    {
        if(premierAnglePositif != anglePositif(listePoints[i-1],point, listePoints[i]))
            return false;
    }

    return true;


}

void Polygone::deplacer(int dx, int dy)
{
    for(int i =0; i<nbPoints; i++)
    {
        listePoints[i].first += dx;
        listePoints[i].second += dy;

    }
}

bool Polygone::anglePositif(pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
    float abX = b.first - a.first;
    float abY = b.second-a.second;
    float cbX = b.first - c.first;
    float cbY = b.second - c.second;

    float scalaire = (abX * cbX + abY * cbY);
    float vectoriel = (abX * cbY - abY * cbX);

    float alpha = atan2(vectoriel, scalaire);

    if((int) floor(alpha * 180. / 3.14159265359 + 0.5) < 0)
        return false;

    return true;
}

ptr_Forme Polygone::clone()
{
	Polygone * polygoneClone = new Polygone(nom, nbPoints);
	for(int i =0; i<nbPoints; i++)
		polygoneClone->ajouterPoint(listePoints[i].first, listePoints[i].second);

	return polygoneClone;
}
