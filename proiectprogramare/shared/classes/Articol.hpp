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

    // Getters
    string getCod() const;
    string getTitlu() const;
    string getContinut() const;
    int getNumarLove() const;
    int getNumarLike() const;
    int getNumarDislike() const;
    const vector<Comentariu>& getComentarii() const;

    // Setters
    void setTitlu(const string& newTitlu);
    void setContinut(const string& newContinut);
    void addLove();
    void addLike();
    void addDislike();
    void addComentariu(const Comentariu& comentariu);

    // Overload << operator
    friend ostream& operator<<(ostream& os, const Articol& articol);
};

#endif // ARTICOL_HPP
