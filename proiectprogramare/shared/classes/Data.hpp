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
    
    friend ostream& operator<<(ostream& os, const Data& data);

    // Getteri
    int getZi() const;
    int getLuna() const;
    int getAn() const;
};

#endif // DATA_HPP
