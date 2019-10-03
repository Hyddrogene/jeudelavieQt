#include "stockdecelulle.hh"

//=====================================================================================================
//=====================================================================================================

stockcellule::stockcellule(int x,int y):
    taillex(x),tailley(y){
    Cellule a;
    std::vector<Cellule> corne;
    for(int i(0);i<y;i++){corne.push_back(a);}
    corne.shrink_to_fit();
    for(int i(0);i<x;i++){stock.push_back(corne);}
    stock.shrink_to_fit();
    stockpassager=this->initstock();
}

//=====================================================================================================
//=====================================================================================================

bool stockcellule::positionxy(int x, int y)const{
    unsigned int x1=static_cast<unsigned int >(x);
    unsigned int y1=static_cast<unsigned int >(y);
    Cellule a=stock[x1][y1];
    return a.vistu();
}

//=====================================================================================================
//=====================================================================================================

void stockcellule::changelaviexy(int x, int y){
    unsigned int x1=static_cast<unsigned int >(x)-1;
    unsigned int y1=static_cast<unsigned int >(y)-1;
    stock[x1][y1].changestade(not(stock[x1][y1].vistu()));
}

//=====================================================================================================
//======================================================================================================

void stockcellule::toursuivant(){

    std::vector<std::vector<Cellule>> nouvostock;
    nouvostock=stockpassager;
     stockpassager=stock;
    for (unsigned int i(0);i<static_cast<unsigned int>(taillex);i++){
        for (unsigned int j(0);j<static_cast<unsigned int>(tailley);j++){
            int compte=compteur(i,j);
            /*if(compte>1){
            std::cout<<" "<<compte<<" i:"<<i<<" j :"<<j;
            }*/
            if(compte>1 && compte<4){
                if(compte==2){
                    if(stock[i][j].vistu()){
                        stockpassager[i][j].rendlavie();
                    }
                    else {
                        stockpassager[i][j].donnelamort();
                    }
                }
                else {
                    stockpassager[i][j].rendlavie();
                }
            }
            else{
                stockpassager[i][j].donnelamort();
            }
        }
    }

    stock=stockpassager;
    stockpassager=nouvostock;
}

//=====================================================================================================
//=====================================================================================================

int stockcellule::compteur(unsigned int i,unsigned int j){

    int compteur(0);

//=========================================================== if interieur

            if(0<i && i<static_cast<unsigned int>(taillex-1) && 0<j && j<static_cast<unsigned int>(tailley-1)){
compteur=stock[i-1][j-1].vistu()+stock[i][j-1].vistu()+stock[i+1][j-1].vistu()+stock[i-1][j].vistu()+stock[i+1][j].vistu()+stock[i-1][j+1].vistu()+stock[i][j+1].vistu()+stock[i+1][j+1].vistu();
            }

//=========================================================== else exterieur

            else{
//=============================test 1

            if(i==0){
                if(j==0){
                    compteur=stock[1][0].vistu()+stock[0][1].vistu()+stock[1][1].vistu();
                }
                else{
                    if(j<static_cast<unsigned int>(tailley-1)){
                        compteur=stock[i][j-1].vistu()+stock[i+1][j-1].vistu()+stock[i+1][j].vistu()+stock[i][j+1].vistu()+stock[i+1][j+1].vistu();
                    }
                }
            }//fin if

//=============================test 2

            if(i==static_cast<unsigned int>(taillex-1)){
                if(j==0){
                    compteur=stock[i-1][j].vistu()+stock[i-1][j+1].vistu()+stock[i][j+1].vistu();
                }
                else{
                    if(j<static_cast<unsigned int>(tailley-1)){
                        compteur=stock[i][j-1].vistu()+stock[i-1][j-1].vistu()+stock[i-1][j].vistu()+stock[i-1][j+1].vistu()+stock[i][j+1].vistu();
                    }
                }
            } //fin if

//=============================test 3

            if(j==0 && i!=0 && i!= static_cast<unsigned int>(taillex-1) ){

                compteur=stock[i-1][j].vistu()+stock[i-1][j+1].vistu()+stock[i][j+1].vistu()+stock[i+1][j+1].vistu()+stock[i+1][j].vistu();

            } //fin if

//=============================test 4

            if(j==static_cast<unsigned int>(tailley-1)){
                if(i==0){
                    compteur=stock[i][j-1].vistu()+stock[i+1][j-1].vistu()+stock[i+1][j].vistu();
                }
                else{
                    if(i==static_cast<unsigned int>(taillex-1)){
                        compteur=stock[i-1][j].vistu()+stock[i-1][j-1].vistu()+stock[i][j-1].vistu();
                    }
                    else {
                        compteur=stock[i-1][j].vistu()+stock[i-1][j-1].vistu()+stock[i][j-1].vistu()+stock[i+1][j-1].vistu()+stock[i+1][j].vistu();
                    }
                }
            }//fin if

//============================= return
        }//fin if
            return  compteur;
}

//=====================================================================================================
//=====================================================================================================

void stockcellule::changelestock(std::vector<std::vector<Cellule>> nouvostock){
    stock.clear();
    stock=nouvostock;
}

//=====================================================================================================
//=====================================================================================================

void stockcellule::affiche(){

    for (unsigned int i(0);i<static_cast<unsigned int>(tailley);i++){
        std::cout<<std::endl;
        for (unsigned int j(0);j<static_cast<unsigned int>(taillex);j++){
            if(stock[j][i].vistu()){
                 std::cout<<"x";
            }
            else {
                 std::cout<<"o";
            }


        }
    }
}


std::vector<std::vector<Cellule>> stockcellule::initstock (){

    std::vector<std::vector<Cellule>> stock2;

    Cellule a;
    std::vector<Cellule> corne;
    for(int i(0);i<tailley;i++){corne.push_back(a);}
    corne.shrink_to_fit();
    for(int i(0);i<taillex;i++){stock2.push_back(corne);}
    stock.shrink_to_fit();
    return stock2;
}

//=====================================================================================================
//=====================================================================================================

int stockcellule::compteurdecelvivante(){
    int comptage(0);
    for(unsigned int i=0;i<static_cast<unsigned int>(taillex);i++){
        for(unsigned int j=0;j<static_cast<unsigned int>(tailley);j++){
            if(stock[i][j].vistu())
                comptage++;
        }
    }
    return comptage;
}

//=====================================================================================================
//=====================================================================================================

int stockcellule::compteurdecelmorte(){
    int comptage(0);
    for(unsigned int i=0;i<static_cast<unsigned int>(taillex);i++){
        for(unsigned int j=0;j<static_cast<unsigned int>(tailley);j++){
            if(not(stock[i][j].vistu()))
                comptage++;
        }
    }
    return comptage;
}

//=====================================================================================================
//=====================================================================================================

void stockcellule::donnelaviexy(unsigned int x,unsigned int y){
    stock[x][y].rendlavie();
}

//=====================================================================================================
//=====================================================================================================

void stockcellule::donnelamortxy(unsigned int x, unsigned int y){
    stock[x][y].donnelamort();
}

