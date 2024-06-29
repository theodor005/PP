#include "Data.hpp"
using namespace std;

Data::Data(int zi, int luna, int an) : zi(zi), luna(luna), an(an) {}

// Getters
int Data::getZi() const { return zi; }
int Data::getLuna() const { return luna; }
int Data::getAn() const { return an; }

// Overload << operator
ostream& operator<<(ostream& os, const Data& data) {
    os << data.zi << "/" << data.luna << "/" << data.an;
    return os;
}
