#include "Data.hpp"

// Constructor
Data::Data(int zi, int luna, int an) : zi(zi), luna(luna), an(an) {}

// Metode de acces
int Data::getZi() const { return zi; }
int Data::getLuna() const { return luna; }
int Data::getAn() const { return an; }

// Metodă pentru afișarea datei
void Data::afiseaza() const {
    cout << zi << "/" << luna << "/" << an << endl;
}
