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

    // Getters
    string getCodArticol() const;
    string getContinut() const;
    Data getData() const;

    // Overload << operator
    friend ostream& operator<<(ostream& os, const Comentariu& comentariu);
};

#endif // COMENTARIU_HPP
