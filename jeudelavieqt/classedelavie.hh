#ifndef CLASSEDELAVIE_HH
#define CLASSEDELAVIE_HH

class Cellule {
private:
    bool envie;

public :
    Cellule():envie(false){}
    bool vistu(){return envie;}
    void rendlavie(){envie=true;}
    void donnelamort(){envie=false;}
    void changestade(bool okay){envie=okay;}

};

#endif // CLASSEDELAVIE_HH
