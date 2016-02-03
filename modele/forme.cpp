#include "forme.h"

Forme::Forme(string name)
{
    nom = name;
}

Forme::Forme(const Forme& forme)
{
	nom = forme.nom;
}

Forme::~Forme()
{

}
