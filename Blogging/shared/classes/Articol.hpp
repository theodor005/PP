#ifndef ARTICOL_HPP
#define ARTICOL_HPP

#include <string>
#include <vector>
#include "Comentariu.hpp"

class Articol {
private:
    std::string cod;
    std::string titlu;
    std::string continut;
    int love;
    int like;
    int dislike;
    std::vector<Comentariu> comentarii;

public:
    Articol(const std::string& cod, const std::string& titlu, const std::string& continut);
    
    std::string getCod() const;
    std::string getTitlu() const;
    std::string getContinut() const;
    int getLove() const;
    int getLike() const;
    int getDislike() const;
    std::vector<Comentariu> getComentarii() const;
    
    void setTitlu(const std::string& titlu);
    void setContinut(const std::string& continut);
    void addLove();
    void addLike();
    void addDislike();
    void addComentariu(const Comentariu& comentariu);

    friend std::ostream& operator<<(std::ostream& os, const Articol& articol);
};

#endif // ARTICOL_HPP
