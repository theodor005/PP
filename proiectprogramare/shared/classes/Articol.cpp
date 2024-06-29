#include "Articol.hpp"
using namespace std;

Articol::Articol(string cod, string titlu, string continut)
    : cod_de_articol(cod), titlu(titlu), continut(continut), numar_love(0), numar_like(0), numar_dislike(0) {}

// Getters
string Articol::getCod() const { return cod_de_articol; }
string Articol::getTitlu() const { return titlu; }
string Articol::getContinut() const { return continut; }
int Articol::getNumarLove() const { return numar_love; }
int Articol::getNumarLike() const { return numar_like; }
int Articol::getNumarDislike() const { return numar_dislike; }
const vector<Comentariu>& Articol::getComentarii() const { return comentarii; }

// Setters
void Articol::setTitlu(const string& newTitlu) { titlu = newTitlu; }
void Articol::setContinut(const string& newContinut) { continut = newContinut; }
void Articol::addLove() { numar_love++; }
void Articol::addLike() { numar_like++; }
void Articol::addDislike() { numar_dislike++; }
void Articol::addComentariu(const Comentariu& comentariu) { comentarii.push_back(comentariu); }

// Overload << operator
ostream& operator<<(ostream& os, const Articol& articol) {
    os << "Cod: " << articol.cod_de_articol << "\nTitlu: " << articol.titlu << "\nContinut: " << articol.continut
       << "\nLove: " << articol.numar_love << "\nLike: " << articol.numar_like << "\nDislike: " << articol.numar_dislike
       << "\nComentarii:\n";
    for (const auto& comentariu : articol.comentarii) {
        os << comentariu << "\n";
    }
    return os;
}
