#include "Articol.hpp"

Articol::Articol(const std::string& cod, const std::string& titlu, const std::string& continut)
    : cod(cod), titlu(titlu), continut(continut), love(0), like(0), dislike(0) {}

std::string Articol::getCod() const {
    return cod;
}

std::string Articol::getTitlu() const {
    return titlu;
}

std::string Articol::getContinut() const {
    return continut;
}

int Articol::getLove() const {
    return love;
}

int Articol::getLike() const {
    return like;
}

int Articol::getDislike() const {
    return dislike;
}

std::vector<Comentariu> Articol::getComentarii() const {
    return comentarii;
}

void Articol::setTitlu(const std::string& titlu) {
    this->titlu = titlu;
}

void Articol::setContinut(const std::string& continut) {
    this->continut = continut;
}

void Articol::addLove() {
    ++love;
}

void Articol::addLike() {
    ++like;
}

void Articol::addDislike() {
    ++dislike;
}

void Articol::addComentariu(const Comentariu& comentariu) {
    comentarii.push_back(comentariu);
}

std::ostream& operator<<(std::ostream& os, const Articol& articol) {
    os << "Cod: " << articol.cod << "\n"
       << "Titlu: " << articol.titlu << "\n"
       << "Continut: " << articol.continut << "\n"
       << "Love: " << articol.love << "\n"
       << "Like: " << articol.like << "\n"
       << "Dislike: " << articol.dislike << "\n"
       << "Comentarii:\n";
    for (const auto& comentariu : articol.comentarii) {
        os << comentariu << "\n";
    }
    return os;
}
