#include "union.h"

Union::Union(string name, ptr_Forme formes[], int nb) : Forme(name)
{
    formesAUnir = formes;
    nbFormes = nb;

}

Union::~Union()
{
	for(int i = 0; i < nbFormes; i++)
		delete formesAUnir[i];
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

void Union::display()
{
	cout << "UNION : " << nom << ", contient " << nbFormes << "forme(s)." << endl;
}