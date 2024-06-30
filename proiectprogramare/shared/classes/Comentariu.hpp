#ifndef COMENTARIU_HPP
#define COMENTARIU_HPP

#include <string>

using namespace std;

class Comentariu {
public:
    Comentariu(int id, const string& text);

    int getId() const;
    string getText() const;

    void setId(int id);
    void setText(const string& text);

    friend ostream& operator<<(ostream& os, const Comentariu& comentariu);

private:
    int id;
    string text;
};

#endif // COMENTARIU_HPP
