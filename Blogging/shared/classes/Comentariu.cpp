#include "Comentariu.hpp"

Comentariu::Comentariu(std::string cod, std::string continut, Data data)
    : cod_articol(cod), continut(continut), data(data) {}

void Comentariu::display() const {
    std::cout << "Comentariu pentru articolul " << cod_articol << ": " << continut << " (Data: " << data << ")\n";
}

std::ostream& operator<<(std::ostream& out, const Comentariu& comentariu) {
    out << "Comentariu pentru articolul " << comentariu.cod_articol << ": " << comentariu.continut << " (Data: " << comentariu.data << ")\n";
    return out;
}

std::string Comentariu::getCodArticol() const { return cod_articol; }

std::string Comentariu::getContinut() const { return continut; }

Data Comentariu::getData() const { return data; }
