#include "Comentariu.hpp"
using namespace std;

Comentariu::Comentariu(string cod, string continut, Data data)
    : cod_de_articol(cod), continut(continut), data(data) {}

// Getters
string Comentariu::getCodArticol() const { return cod_de_articol; }
string Comentariu::getContinut() const { return continut; }
Data Comentariu::getData() const { return data; }

// Overload << operator
ostream& operator<<(ostream& os, const Comentariu& comentariu) {
    os << "Cod Articol: " << comentariu.cod_de_articol << "\nContinut: " << comentariu.continut << "\nData: " << comentariu.data;
    return os;
}
