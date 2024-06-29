#include "Comentariu.hpp"

Comentariu::Comentariu(string cod, string continut, Data data)
    : cod_de_articol(cod), continut(continut), data(data) {}

ostream& operator<<(ostream& os, const Comentariu& comentariu) {
    os << "Cod articol: " << comentariu.cod_de_articol << "\nContinut: " << comentariu.continut
       << "\nData: " << comentariu.data;
    return os;
}

// Getteri
string Comentariu::getCodArticol() const { return cod_de_articol; }
string Comentariu::getContinut() const { return continut; }
Data Comentariu::getData() const { return data; }
