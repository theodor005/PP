#ifndef COMENTARIU_HPP
#define COMENTARIU_HPP

#include <string>
#include "Data.hpp"

using namespace std;

class Comentariu {
private:
    string cod_de_articol;
    string continut;
    Data data;

public:
    Comentariu(string cod, string continut, Data data);
    
    friend ostream& operator<<(ostream& os, const Comentariu& comentariu);

    // Getteri
    string getCodArticol() const;
    string getContinut() const;
    Data getData() const;
};

#endif // COMENTARIU_HPP
