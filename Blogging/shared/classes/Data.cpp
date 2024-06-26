#include "Data.hpp"

Data::Data(int zi, int luna, int an) : zi(zi), luna(luna), an(an) {}

void Data::display() const {
    std::cout << zi << "/" << luna << "/" << an << "\n";
}

std::ostream& operator<<(std::ostream& out, const Data& data) {
    out << data.zi << "/" << data.luna << "/" << data.an;
    return out;
}

int Data::getZi() const { return zi; }

int Data::getLuna() const { return luna; }

int Data::getAn() const { return an; }
