#include "Articol.hpp"

Articol::Articol(int id, const std::string& titlu, const std::string& descriere, int numarLike, int numarDislike, int numarLove)
    : id(id), titlu(titlu), descriere(descriere), numarLike(numarLike), numarDislike(numarDislike), numarLove(numarLove) {}

int Articol::getId() const {
    return id;
}

std::string Articol::getTitlu() const {
    return titlu;
}

std::string Articol::getDescriere() const {
    return descriere;
}

int Articol::getNumarLike() const {
    return numarLike;
}

int Articol::getNumarDislike() const {
    return numarDislike;
}

int Articol::getNumarLove() const {
    return numarLove;
}

void Articol::setTitlu(const std::string& titlu) {
    this->titlu = titlu;
}

void Articol::setDescriere(const std::string& descriere) {
    this->descriere = descriere;
}

void Articol::adaugaLike() {
    ++numarLike;
}

void Articol::adaugaDislike() {
    ++numarDislike;
}

void Articol::adaugaLove() {
    ++numarLove;
}

std::ostream& operator<<(std::ostream& os, const Articol& articol) {
    os << articol.id << "\n" << articol.titlu << "\n" << articol.descriere << "\n"
       << articol.numarLove << "\n" << articol.numarLike << "\n" << articol.numarDislike;
    return os;
}
