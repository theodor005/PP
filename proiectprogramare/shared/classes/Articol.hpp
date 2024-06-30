#ifndef ARTICOL_HPP
#define ARTICOL_HPP

#include <string>
#include <iostream>

class Articol {
private:
    int id;
    std::string titlu;
    std::string descriere;
    int numarLike;
    int numarDislike;
    int numarLove;

public:
    Articol(int id, const std::string& titlu, const std::string& descriere, int numarLike = 0, int numarDislike = 0, int numarLove = 0);

    int getId() const;
    std::string getTitlu() const;
    std::string getDescriere() const;
    int getNumarLike() const;
    int getNumarDislike() const;
    int getNumarLove() const;

    void setTitlu(const std::string& titlu);
    void setDescriere(const std::string& descriere);
    
    void adaugaLike();
    void adaugaDislike();
    void adaugaLove();

    friend std::ostream& operator<<(std::ostream& os, const Articol& articol); // Supraincarcare operator <<
};

#endif // ARTICOL_HPP
