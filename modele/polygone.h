#ifndef POLYGONE_H
#define POLYGONE_H

#include  <utility>
#include "forme.h"

using namespace std;

class Polygone : public Forme
{

protected:
    int sommet;
    pair<int, int> *listePoints;
    int nbPoints;

public:
    Polygone(string name, int nb);

    bool ajouterPoint(int x, int y);
    virtual ~Polygone();

    virtual bool contient(std::pair<int,int> point);
    void deplacer(int dx, int dy);
	virtual ptr_Forme clone();
	virtual void display();
	int getNbPoints(){return nbPoints;}
	pair<int,int> * getListePoints(){return listePoints;}

private:
	bool anglePositif(pair<int,int> a, pair<int,int> b, pair<int,int> c);

	

};

#endif // POLYGONE_H
