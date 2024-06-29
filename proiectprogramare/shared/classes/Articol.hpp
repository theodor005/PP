#ifndef ARTICOL_HPP
#define ARTICOL_HPP

#include <string>
#include <vector>
#include "Comentariu.hpp"

using namespace std;

class Articol {
private:
    string cod_de_articol;
    string titlu;
    string continut;
    int numar_love;
    int numar_like;
    int numar_dislike;
    vector<Comentariu> comentarii;

public:
    Articol(string cod, string titlu, string continut);
    
    void adaugaLove();
    void adaugaLike();
    void adaugaDislike();
    void adaugaComentariu(const Comentariu& comentariu);

    friend ostream& operator<<(ostream& os, const Articol& articol);

    // Getteri și setteri
    string getCod() const;
    string getTitlu() const;
    string getContinut() const;
    int getLove() const;
    int getLike() const;
    int getDislike() const;
    vector<Comentariu> getComentarii() const;
};

#endif // ARTICOL_HPP
