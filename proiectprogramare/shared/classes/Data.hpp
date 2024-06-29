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
    Data(int zi, int luna, int an);

    // Getters
    int getZi() const;
    int getLuna() const;
    int getAn() const;

    // Overload << operator
    friend ostream& operator<<(ostream& os, const Data& data);
};

#endif // DATA_HPP
