#ifndef COMENTARIU_HPP
#define COMENTARIU_HPP

#include <iostream>
#include <string>
#include "Data.hpp"

class Comentariu {
private:
    std::string cod_articol;
    std::string continut;
    Data data;

public:
    Comentariu(std::string cod, std::string continut, Data data);
    void display() const;

    friend std::ostream& operator<<(std::ostream& out, const Comentariu& comentariu);

    std::string getCodArticol() const;
    std::string getContinut() const;
    Data getData() const;
};

#endif 
