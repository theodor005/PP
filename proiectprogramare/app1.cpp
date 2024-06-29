#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "shared/classes/Articol.cpp"
#include "shared/classes/Comentariu.cpp"
#include "shared/classes/Data.cpp"
using namespace std;

vector<Articol> loadArticole() {
    vector<Articol> articole;
    ifstream inFile("shared/files/articole.txt");
    if (inFile.is_open()) {
        int numar_articole;
        inFile >> numar_articole;
        for (int i = 0; i < numar_articole; ++i) {
            string cod, titlu, continut;
            int love, like, dislike, numar_comentarii;
            inFile >> cod >> titlu >> continut >> love >> like >> dislike >> numar_comentarii;
            Articol articol(cod, titlu, continut);
            for (int j = 0; j < numar_comentarii; ++j) {
                string coment_cod, coment_continut;
                int zi, luna, an;
                inFile >> coment_cod >> coment_continut >> zi >> luna >> an;
                Comentariu comentariu(coment_cod, coment_continut, Data(zi, luna, an));
                articol.addComentariu(comentariu);
            }
            articole.push_back(articol);
        }
    }
    return articole;
}

void saveArticole(const vector<Articol>& articole) {
    ofstream outFile("shared/files/articole.txt");
    if (outFile.is_open()) {
        outFile << articole.size() << endl;
        for (const auto& articol : articole) {
            outFile << articol.getCod() << " " << articol.getTitlu() << " " << articol.getContinut() << " "
                    << articol.getNumarLove() << " " << articol.getNumarLike() << " " << articol.getNumarDislike() << " "
                    << articol.getComentarii().size() << endl;
            for (const auto& comentariu : articol.getComentarii()) {
                outFile << comentariu.getCodArticol() << " " << comentariu.getContinut() << " "
                        << comentariu.getData().getZi() << " " << comentariu.getData().getLuna() << " " << comentariu.getData().getAn() << endl;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Utilizare: ./app_1.exe [comanda] [argumente]" << endl;
        return 1;
    }

    string comanda = argv[1];

    if (comanda == "vizualizare_articole") {
        auto articole = loadArticole();
        for (const auto& articol : articole) {
            cout << articol << endl;
        }
    } else if (comanda == "adaugare_articol") {
        if (argc < 5) {
            cout << "Utilizare: ./app_1.exe adaugare_articol <cod_de_articol> <titlu> <continut>" << endl;
            return 1;
        }
        string cod = argv[2];
        string titlu = argv[3];
        string continut = argv[4];
        auto articole = loadArticole();
        articole.push_back(Articol(cod, titlu, continut));
        saveArticole(articole);
    } else if (comanda == "stergere_articol") {
        if (argc < 3) {
            cout << "Utilizare: ./app_1.exe stergere_articol <cod_de_articol>" << endl;
            return 1;
        }
        string cod = argv[2];
        auto articole = loadArticole();
        articole.erase(remove_if(articole.begin(), articole.end(),
                                 [&](const Articol& articol) { return articol.getCod() == cod; }), articole.end());
        saveArticole(articole);
    } else if (comanda == "modificare_articol") {
        if (argc < 5) {
            cout << "Utilizare: ./app_1.exe modificare_articol <cod_de_articol> <titlu> <continut>" << endl;
            return 1;
        }
        string cod = argv[2];
        string newTitlu = argv[3];
        string newContinut = argv[4];
        auto articole = loadArticole();
        for (auto& articol : articole) {
            if (articol.getCod() == cod) {
                articol.setTitlu(newTitlu);
                articol.setContinut(newContinut);
                break;
            }
        }
        saveArticole(articole);
    } else {
        cout << "Comanda necunoscuta: " << comanda << endl;
    }

    return 0;
}
