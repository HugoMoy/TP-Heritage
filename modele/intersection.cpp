#include "intersection.h"

Intersection::Intersection(string name, ptr_Forme formes[], int nb) : Forme(name)
{
    formesAIntersecter = new ptr_Forme[nbFormes];
    nbFormes = nb;

    for(int i = 0; i<nb; i++)
    {
        formesAIntersecter[i]=formes[i];
    }

}

Intersection::~Intersection()
{
	for(int i = 0; i < nbFormes; i++)
		delete formesAIntersecter[i];
}

bool Intersection::contient(pair<int, int> point)
{
    for(int i = 0; i< nbFormes; i++)
    {
        if(!formesAIntersecter[i]->contient(point))
            return false;
    }

    return true;
}

void Intersection::deplacer(int dx, int dy)
{
    for(int i =0; i < nbFormes; i++)
    {
        formesAIntersecter[i]->deplacer(dx, dy);
    }
}

ptr_Forme Intersection::clone()
{
	ptr_Forme * formes = new ptr_Forme[nbFormes];
	for(int i =0; i < nbFormes; i++)
		formes[i] = formesAIntersecter[i]->clone();

	Intersection * intersectionClone = new Intersection(nom, formes, nbFormes);
	return intersectionClone;
}
