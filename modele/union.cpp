#include "union.h"

Union::Union(string name, ptr_Forme formes[], int nb) : Forme(name)
{
    formesAUnir = new ptr_Forme[nb];
    nbFormes = nb;

    for(int i = 0; i<nb; i++)
    {
        formesAUnir[i]=formes[i];
    }

}

Union::~Union()
{
}

bool Union::contient(pair<int, int> point)
{
    for(int i = 0; i< nbFormes; i++)
    {
        if(formesAUnir[i]->contient(point))
            return true;
    }

    return false;
}

void Union::deplacer(int dx, int dy)
{
    for(int i =0; i < nbFormes; i++)
    {
        formesAUnir[i]->deplacer(dx, dy);
    }
}

ptr_Forme Union::clone()
{
	ptr_Forme * formes = new ptr_Forme[nbFormes];
	for(int i =0; i < nbFormes; i++)
		formes[i] = formesAUnir[i]->clone();

	Union * unionClone = new Union(nom, formes, nbFormes);
	return unionClone;
}
