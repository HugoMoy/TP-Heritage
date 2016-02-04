#include "segment.h"

Segment::Segment(string name, int x1, int y1, int x2, int y2) : Forme(name)
{
    point1=pair<int,int>(x1,y1);
    point2 = pair<int,int>(x2, y2);
}

Segment::~Segment()
{

}

bool Segment::contient(pair<int, int> point)
{
    return (point.first>=point1.first && point.first <= point2.first && (point.second-point1.second) == point.first*(point2.second-point1.second)/(point2.first-point1.first));
}

void Segment::deplacer(int dx, int dy)
{
    point1.first += dx;
    point2.first += dx;
    point1.second += dy;
    point2.second += dy;
}

ptr_Forme Segment::clone()
{
	Segment * segmentClone = new Segment(nom, point1.first, point1.second, point2.first, point2.second);
	return segmentClone;
}

void Segment::display()
{
	cout << "SEGMENT contenant les points (" << point1.first << ", " << point1.second <<") ; (" << point2.first << ", " << point2.second <<")" << endl;
}