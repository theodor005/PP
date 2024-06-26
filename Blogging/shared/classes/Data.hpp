#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
private:
    int zi;
    int luna;
    int an;

public:
    Data(int zi, int luna, int an);
    void display() const;

    // Overloading operator<< for displaying a date
    friend std::ostream& operator<<(std::ostream& out, const Data& data);

    int getZi() const;
    int getLuna() const;
    int getAn() const;
};

#endif // DATA_HPP
