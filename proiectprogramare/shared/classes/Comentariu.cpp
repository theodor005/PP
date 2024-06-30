#include "Comentariu.hpp"
#include <iostream>

using namespace std;

Comentariu::Comentariu(int id, const string& text)
    : id(id), text(text) {}

int Comentariu::getId() const { return id; }
string Comentariu::getText() const { return text; }

void Comentariu::setId(int id) { this->id = id; }
void Comentariu::setText(const string& text) { this->text = text; }

ostream& operator<<(ostream& os, const Comentariu& comentariu) {
    os << "Comentariu ID: " << comentariu.getId() << ", Text: " << comentariu.getText();
    return os;
}
