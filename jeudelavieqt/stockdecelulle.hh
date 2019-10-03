#ifndef STOCKDECELULLE_HH
#define STOCKDECELULLE_HH
#include <vector>
#include <iostream>
#include "classedelavie.hh"

class stockcellule{
private:
    std::vector<std::vector<Cellule>> stock;
    std::vector<std::vector<Cellule>> stockpassager;
    int taillex;
    int tailley;
public:
    stockcellule(int x,int y);
    void donnelavie();
    void toursuivant();
    int gettaillex(){return taillex;}
    int gettailley(){return tailley;}

    void changex(int x2){taillex=x2;}
    void changey(int y2){tailley=y2;}

    bool positionxy(int x, int y)const;
    void changelaviexy(int x,int y);
    int compteur(unsigned int i, unsigned int j);
    void changelestock(std::vector<std::vector<Cellule>> nouvostock);
    std::vector<std::vector<Cellule>> stockout(){return  stock;}
    std::vector<std::vector<Cellule>> stock2out(){return  stockpassager;}
    void affiche();
    std::vector<std::vector<Cellule>> initstock ();

    void suprime(){stock.clear();}
    int compteurdecelvivante();
    int compteurdecelmorte();

    void donnelaviexy(unsigned int x,unsigned int y);
    void donnelamortxy(unsigned int x,unsigned int y);

};

#endif // STOCKDECELULLE_HH
