#ifndef UNION_H
#define UNION_H

#include "forme.h"

class Union : public Forme
{
private:
    ptr_Forme *formesAUnir;
    int nbFormes;

public:
    Union(string name, ptr_Forme formes[], int nb);
    virtual ~Union();

    bool contient(pair<int, int> point);
    void deplacer(int dx, int dy);
	ptr_Forme clone();
};

#endif // UNION_H
