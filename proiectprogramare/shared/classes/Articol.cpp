#include "Articol.hpp"

Articol::Articol(string cod, string titlu, string continut)
    : cod_de_articol(cod), titlu(titlu), continut(continut), numar_love(0), numar_like(0), numar_dislike(0) {}

void Articol::adaugaLove() {
    numar_love++;
}

void Articol::adaugaLike() {
    numar_like++;
}

void Articol::adaugaDislike() {
    numar_dislike++;
}

void Articol::adaugaComentariu(const Comentariu& comentariu) {
    comentarii.push_back(comentariu);
}

ostream& operator<<(ostream& os, const Articol& articol) {
    os << "Cod: " << articol.cod_de_articol << "\nTitlu: " << articol.titlu
       << "\nContinut: " << articol.continut << "\nLove: " << articol.numar_love
       << "\nLike: " << articol.numar_like << "\nDislike: " << articol.numar_dislike
       << "\nComentarii:\n";
    for (const auto& comentariu : articol.comentarii) {
        os << comentariu << "\n";
    }
    return os;
}

// Getteri și setteri
string Articol::getCod() const { return cod_de_articol; }
string Articol::getTitlu() const { return titlu; }
string Articol::getContinut() const { return continut; }
int Articol::getLove() const { return numar_love; }
int Articol::getLike() const { return numar_like; }
int Articol::getDislike() const { return numar_dislike; }
vector<Comentariu> Articol::getComentarii() const { return comentarii; }
