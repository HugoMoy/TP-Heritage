#ifndef FABRIQUE_H
#define FABRIQUE_H
//#include "Forme.h"
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Fabrique
{
    public:
        Fabrique();
        virtual ~Fabrique();
        void creerR(string nom, int x1, int y1, int x2, int y2);
        void creerS(string nom, int x1, int y1, int x2, int y2);
        void creerPC(string nom, int taille, int c[]);
        void unir(string nom, int taille, string f[]);
        void intersection(string nom, int taille, string f[]);
        bool appartenance(string nom, int x, int y);
        void nettoyer();
        void hit();
        void lister();
        void supprimer(string nom);
        void bouger(string nom, int dx, int dy);


    protected:
    private:
        vector<string> actionsListe;
        vector<string> undoListe;
        //vector<Forme> listeFormes;
};

#endif // FABRIQUE_H
