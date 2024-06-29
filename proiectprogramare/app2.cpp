#include <iostream>
#include <fstream>
#include <vector>
#include "shared/classes/Articol.cpp"
#include "shared/classes/Comentariu.cpp"
#include "shared/classes/Data.cpp"
using namespace std;

vector<Comentariu> loadComentarii() {
    vector<Comentariu> comentarii;
    ifstream inFile("shared/files/comentarii.txt");
    if (inFile.is_open()) {
        string cod, continut;
        int zi, luna, an;
        while (inFile >> cod >> continut >> zi >> luna >> an) {
            comentarii.emplace_back(cod, continut, Data(zi, luna, an));
        }
    }
    return comentarii;
}

void saveComentarii(const vector<Comentariu>& comentarii) {
    ofstream outFile("shared/files/comentarii.txt");
    if (outFile.is_open()) {
        for (const auto& comentariu : comentarii) {
            outFile << comentariu.getCodArticol() << " " << comentariu.getContinut() << " "
                    << comentariu.getData().getZi() << " " << comentariu.getData().getLuna() << " " << comentariu.getData().getAn() << endl;
        }
    }
}

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
        cout << "Utilizare: ./app_2.exe [comanda] [argumente]" << endl;
        return 1;
    }

    string comanda = argv[1];

    if(comanda == "help"){
      cout << "Comenzi:" << endl
      << "Pentru a vedea comentariile unui articol: ./app2.exe vizualizare_comentarii <cod_de_articol>" << endl
      << "Pentru a adauga un comentariu unui articol: ./app2.exe adaugare_comentariu <cod_de_articol> <continut>" << endl
      << "Pentru a da love unui articol: /app2.exe love_articol <cod_de_articol>" << endl
      << "Pentru a da like unui articol: /app2.exe like_articol <cod_de_articol>" << endl
      << "Pentru a da dislike unui articol: /app2.exe dislike_articol <cod_de_articol>" << endl;
    } else if (comanda == "adaugare_comentariu") {
        if (argc < 4) {
            cout << "Utilizare: ./app_2.exe adaugare_comentariu <cod_de_articol> <continut>" << endl;
            return 1;
        }
        string cod = argv[2];
        string continut = argv[3];
        auto comentarii = loadComentarii();
        comentarii.emplace_back(cod, continut, Data(28, 6, 2024)); // Example date
        saveComentarii(comentarii);
    } else if (comanda == "vizualizare_comentarii") {
        if (argc < 3) {
            cout << "Utilizare: ./app_2.exe vizualizare_comentarii <cod_de_articol>" << endl;
            return 1;
        }
        string cod = argv[2];
        auto comentarii = loadComentarii();
        for (const auto& comentariu : comentarii) {
            if (comentariu.getCodArticol() == cod) {
                cout << comentariu << endl;
            }
        }
    } else if (comanda == "love_articol" || comanda == "like_articol" || comanda == "dislike_articol") {
        if (argc < 3) {
            cout << "Utilizare: ./app_2.exe " << comanda << " <cod_de_articol>" << endl;
            return 1;
        }
        string cod = argv[2];
        auto articole = loadArticole();
        for (auto& articol : articole) {
            if (articol.getCod() == cod) {
                if (comanda == "love_articol") {
                    articol.addLove();
                } else if (comanda == "like_articol") {
                    articol.addLike();
                } else if (comanda == "dislike_articol") {
                    articol.addDislike();
                }
                break;
            }
        }
        saveArticole(articole);
    } else {
        cout << "Comanda necunoscuta: " << comanda << endl;
    }

    return 0;
}
