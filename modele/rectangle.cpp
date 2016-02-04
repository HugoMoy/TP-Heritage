#include "rectangle.h"

Rectangle::Rectangle(string name, int x1, int y1, int x2, int y2) : Polygone(name, 4)
{

    ajouterPoint(x1, y1);
    ajouterPoint(x2, y1);
    ajouterPoint(x2, y2);
    ajouterPoint(x1, y2);

}

Rectangle::~Rectangle()
{
}

bool Rectangle::contient(pair<int, int> point)
{
    return (point.first>=listePoints[0].first && point.first<=listePoints[2].first && point.second>=listePoints[0].second && point.second<=listePoints[2].second);
}

ptr_Forme Rectangle::clone()
{
	Rectangle * rectangleClone = new Rectangle(nom, listePoints[0].first, listePoints[0].second, listePoints[2].first, listePoints[2].second);

	return rectangleClone;
}

void Rectangle::display()
{
	cout << "RECTANGLE : " << nom << "contenant les points : ";
	for (int i = 0; i < nbPoints-1; i++)
		cout << "(" << listePoints[i].first << ", " << listePoints[i].second << ") ; ";
	cout << "(" << listePoints[nbPoints-1].first << ", " << listePoints[nbPoints-1].second << ")" << endl;
}