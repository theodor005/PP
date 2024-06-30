#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
using namespace std;

class Data {
private:
    int zi;
    int luna;
    int an;

public:
    // Constructor
    Data(int zi, int luna, int an);

    // Metode de acces
    int getZi() const;
    int getLuna() const;
    int getAn() const;

    // Metodă pentru afișarea datei
    void afiseaza() const;
};

#endif // DATA_HPP
