#ifndef SEGMENT_H
#define SEGMENT_H

#include "forme.h"

class Segment : public Forme
{
private :
pair<int, int> point1;
pair<int, int> point2;

public:
    Segment(string name, int x1, int y1, int x2, int y2);
    ~Segment();

    bool contient(pair<int, int> point);
    void deplacer(int dx, int dy);
	ptr_Forme clone();

};

#endif // SEGMENT_H
