#include "Data.hpp"

Data::Data(int zi, int luna, int an) : zi(zi), luna(luna), an(an) {}

ostream& operator<<(ostream& os, const Data& data) {
    os << data.zi << "/" << data.luna << "/" << data.an;
    return os;
}

// Getteri
int Data::getZi() const { return zi; }
int Data::getLuna() const { return luna; }
int Data::getAn() const { return an; }
