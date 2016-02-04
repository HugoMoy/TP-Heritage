#ifndef FORME_H
#define FORME_H

#include <string>
#include <utility>
#include <iostream>

using namespace std;



class Forme
{
protected :
    string nom;

public:
    Forme(string name);
	Forme(const Forme& forme);
    virtual ~Forme();

    virtual bool contient(pair<int, int> point) =0;
    virtual void deplacer(int dx, int dy)=0;
	virtual Forme * clone() = 0;
	virtual void display()=0;

	string getNom(){return nom;}
};

typedef Forme* ptr_Forme;

#endif // FORME_H
