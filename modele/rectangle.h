#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygone.h"


class Rectangle : public Polygone
{


public:
    Rectangle(string name, int x1, int y1, int x2, int y2);
    virtual ~Rectangle();

    bool contient(pair<int, int> point);
	ptr_Forme clone();
	void display();
};

#endif // RECTANGLE_H
