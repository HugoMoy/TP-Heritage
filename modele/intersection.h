#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <utility>
#include "forme.h"

using namespace std;

class Intersection : public Forme
{

private:
    ptr_Forme *formesAIntersecter;
    int nbFormes;

public:
    Intersection(string name, ptr_Forme formes[], int nb);
    virtual ~Intersection();

    bool contient(pair<int, int> point);
    void deplacer(int dx, int dy);
	ptr_Forme clone();

};

#endif // INTERSECTION_H
