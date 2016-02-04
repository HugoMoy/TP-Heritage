#include <iostream>
#include <fstream>
#include <algorithm>
#include "fabriquecommande.h"
#include "../commandes/creerrectangle.h"
#include "../commandes/creerpolygone.h"
#include "../commandes/unir.h"
#include "../commandes/intersecter.h"
#include "../commandes/creersegment.h"
#include "../commandes/vider.h"
#include "../commandes/supprimer.h"
#include "../commandes/deplacer.h"

FabriqueCommande::FabriqueCommande()
{
	indexCommande = -1;
	indexUndo = -1;
}

FabriqueCommande::~FabriqueCommande()
{
	for(int i = 0; i<20; i++)
	{
		delete listeCommande[i];
		delete listeUndo[i];
	}

	for(map<string, ptr_Forme>::iterator it = listeForme.begin(); it!=listeForme.end(); it++)
	{
		delete it->second;
	}
}

bool FabriqueCommande::executerCommande(string commande)
{
	size_t pos = commande.find(" ");
	string arguments = commande.substr(pos);
	commande = commande.substr(0,pos);

	if(commande.compare("R") == 0) //-----------------------------------------------
	{
		pos = arguments.find(" ");
		string nom = arguments.substr(0, pos-1);
		arguments.substr(pos+1);
		int args[4];
		for(int i = 0; i<3; i++)
		{
			pos = arguments.find(" ");
			args[i] = atoi(arguments.substr(0, pos-1).c_str());
			arguments.substr(pos+1);
		}
		args[3] = atoi(arguments.c_str());

		CreerRectangle * commandeRectangle = new CreerRectangle(args, nom, this);

		if(commandeRectangle->exec())
		{
			cout << "OK" << endl;
			ajouterCommande(commandeRectangle);
		}
		else
			cout << "ERR" << endl;
	}

	else if (commande.compare("PC") == 0) //----------------------------------------
	{
		pos = arguments.find(" ");
		string nom = arguments.substr(0, pos-1);
		arguments.substr(pos+1);
		int nbArgs = count(arguments.begin(), arguments.end(), ' ')+1;
		int *args = new int[nbArgs];
		for(int i = 0; i<nbArgs; i++)
		{
			pos = arguments.find(" ");
			args[i] = atoi(arguments.substr(0, pos-1).c_str());
			arguments.substr(pos+1);
		}
		args[nbArgs] = atoi(arguments.c_str());

		
		CreerPolygone * commandePolygone = new CreerPolygone(args, nbArgs, nom, this);

		if(commandePolygone->exec())
		{
			cout << "OK" << endl;
			ajouterCommande(commandePolygone);
		}
		else
			cout << "ERR" << endl;

	}

	else if (commande.compare("OR") == 0) //----------------------------------------
	{
		pos = arguments.find(" ");
		string nom = arguments.substr(0, pos-1);
		arguments.substr(pos+1);
		int nbArgs = count(arguments.begin(), arguments.end(), ' ')+1;
		string *args = new string[nbArgs];
		for(int i = 0; i<nbArgs; i++)
		{
			pos = arguments.find(" ");
			args[i] = arguments.substr(0, pos-1);
			arguments.substr(pos+1);
		}
		args[nbArgs] = arguments;

		
		Unir * commandeUnion = new Unir(nom, args, nbArgs, this);

		if(commandeUnion->exec())
		{
			cout << "OK" << endl;
			ajouterCommande(commandeUnion);
		}
		else
			cout << "ERR" << endl;

	}

	else if (commande.compare("OI") == 0) //----------------------------------------
	{
		pos = arguments.find(" ");
		string nom = arguments.substr(0, pos-1);
		arguments.substr(pos+1);
		int nbArgs = count(arguments.begin(), arguments.end(), ' ')+1;
		string *args = new string[nbArgs];
		for(int i = 0; i<nbArgs; i++)
		{
			pos = arguments.find(" ");
			args[i] = arguments.substr(0, pos-1);
			arguments.substr(pos+1);
		}
		args[nbArgs] = arguments;

		
		Intersecter * commandeIntersection = new Intersecter(nom, args, nbArgs, this);

		if(commandeIntersection->exec())
		{
			cout << "OK" << endl;
			ajouterCommande(commandeIntersection);
		}
		else
			cout << "ERR" << endl;

	}

	else if (commande.compare("S") == 0) //----------------------------------------
	{
		pos = arguments.find(" ");
		string nom = arguments.substr(0, pos-1);
		arguments.substr(pos+1);
		int args[4];
		for(int i = 0; i<3; i++)
		{
			pos = arguments.find(" ");
			args[i] = atoi(arguments.substr(0, pos-1).c_str());
			arguments.substr(pos+1);
		}
		args[3] = atoi(arguments.c_str());

		CreerSegment * commandeSegment = new CreerSegment(nom, args[0], args[1], args[2], args[3], this);

		if(commandeSegment->exec())
		{
			cout << "OK" << endl;
			ajouterCommande(commandeSegment);
		}
		else
			cout << "ERR" << endl;
	}

	else if (commande.compare("UNDO") == 0) //----------------------------------------
	{
		if(indexCommande != -1)
		{
			Commande * commande = listeCommande[indexCommande];
			if(commande->unexec())
			{
				cout << "OK" << endl;
				indexCommande--;
				if(indexUndo != 19)
					listeUndo[++indexUndo] = commande;
				else
				{
					for(int i = 0; i<indexUndo; i++)
					{
						listeUndo[i] = listeUndo[i+1];
					}
					listeUndo[19] = commande;
				}
				historiqueCommande.pop_back();
			}
			else
				cout << "ERR" << endl;

		}
	}

	else if (commande.compare("REDO") == 0) //----------------------------------------
	{
		if(indexUndo != -1)
		{
			Commande * commande = listeUndo[indexUndo];
			if(commande->exec())
			{
				cout << "OK" << endl;
				indexUndo--;
				if(indexCommande != 19)
					listeCommande[++indexCommande] = commande;
				else
				{
					for(int i = 0; i<indexCommande; i++)
					{
						listeCommande[i] = listeCommande[i+1];
					}
					listeCommande[19] = commande;
				}
				historiqueCommande.push_back(commande);
			}
			else
				cout << "ERR" << endl;

		}
	}

	else if (commande.compare("SAVE") == 0) //----------------------------------------
	{
		ofstream sauvegarde(arguments.c_str(), ios::trunc);
		if(sauvegarde)
		{
			for(unsigned int i = 0; i<historiqueCommande.size(); i++)
				sauvegarde << historiqueCommande[i]->saveLine() << endl;
			sauvegarde << "EXIT" << endl;
			cout << "OK" << endl;
			sauvegarde.close();
		}
		else
			cout << "ERR" << endl;
	}

	else if (commande.compare("LOAD") == 0) //----------------------------------------
	{
		ifstream chargement(arguments.c_str());
		string ligne = "";
		if(chargement)
		{
			getline(chargement, ligne);
			while(executerCommande(ligne))
			{

				getline(chargement, ligne);
			}
			chargement.close();
			cout << "OK" << endl;
		}
		else
			cout << "ERR" << endl;
	}

	else if (commande.compare("CLEAR") == 0) //----------------------------------------
	{
		Vider * commandeVider = new Vider(this);

		if(commandeVider->exec())
		{
			cout << "OK" << endl;
			ajouterCommande(commandeVider);
		}
		else
			cout << "ERR" << endl;
	}
	
	else if (commande.compare("HIT") == 0) //----------------------------------------
	{
		pos = arguments.find(" ");
		string nom = arguments.substr(0, pos-1);
		arguments.substr(pos+1);
		
		pos = arguments.find(" ");
		int x = atoi(arguments.substr(0, pos-1).c_str());
		arguments.substr(pos+1);
		int y = atoi(arguments.c_str());
		pair<int, int> point = pair<int, int>(x,y);
		if(find(nom) != nullptr)
		{
			if(find(nom)->contient(point))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "ERR" << endl;
	}

	else if (commande.compare("DELETE") == 0) //----------------------------------------
	{

		int nbArgs = count(arguments.begin(), arguments.end(), ' ')+1;
		string *args = new string[nbArgs];
		for(int i = 0; i<nbArgs; i++)
		{
			pos = arguments.find(" ");
			args[i] = arguments.substr(0, pos-1);
			arguments.substr(pos+1);
		}
		args[nbArgs] = arguments;

		Supprimer * commandeSupprimer = new Supprimer(args, nbArgs, this);

		if(commandeSupprimer->exec())
		{
			cout << "OK" << endl;
			ajouterCommande(commandeSupprimer);
		}
		else
			cout << "ERR" << endl;

	}

	else if (commande.compare("MOVE") == 0) //----------------------------------------
	{
		pos = arguments.find(" ");
		string nom = arguments.substr(0, pos-1);
		arguments.substr(pos+1);
		
		pos = arguments.find(" ");
		int x = atoi(arguments.substr(0, pos-1).c_str());
		arguments.substr(pos+1);
		int y = atoi(arguments.c_str());

		Deplacer * commandeDeplacer = new Deplacer(x, y, nom, this);

		if(commandeDeplacer->exec())
		{
			cout << "OK" << endl;
			ajouterCommande(commandeDeplacer);
		}
		else
			cout << "ERR" << endl;
	}

	else if (commande.compare("LIST") == 0) //----------------------------------------
	{
		for(map<string, ptr_Forme>::iterator it = listeForme.begin(); it != listeForme.end(); it++)
			it->second->display();
	}
	
	else if (commande.compare("EXIT") == 0) //----------------------------------------
	{
		return false;
	}

	return true;
}

void FabriqueCommande::ajouterCommande(Commande * commande)
{			
	
	if(indexCommande != 19)
		listeCommande[++indexCommande] = commande;
	else
	{
		for(int i = 0; i<indexCommande; i++)
		{
			listeCommande[i] = listeCommande[i+1];
		}
		listeUndo[19] = commande;
	}
	historiqueCommande.push_back(commande);
	indexUndo = -1;	
}

bool FabriqueCommande::ajouterForme(Forme * forme)
{
	if(find(forme->getNom()) == nullptr)
	{
		listeForme.insert(pair<string, ptr_Forme>(forme->getNom(), forme->clone()));
		return true;
	}

	return false;
	
}

bool FabriqueCommande::retirerForme(string nom)
{
	ptr_Forme formeARetirer = find(nom);
	if(formeARetirer == nullptr)
		return false;

	delete formeARetirer;
	listeForme.erase(nom);
	return true;
}

bool FabriqueCommande::retirerForme(Forme * forme)
{
	return retirerForme(forme->getNom());
}

ptr_Forme FabriqueCommande::find(string nom)
{
	map<string, ptr_Forme>::iterator it = listeForme.find(nom);
	if(it == listeForme.end())
		return nullptr;
	return it->second;
}

