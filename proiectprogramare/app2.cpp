#include <iostream>
#include <fstream>
#include <vector>
#include "shared/classes/Articol.cpp"
#include "shared/classes/Comentariu.cpp"
#include "shared/classes/Data.cpp"

using namespace std;

vector<Comentariu> incarcaComentarii() {
    vector<Comentariu> comentarii;
    ifstream infile("shared/files/comentarii.txt");
    while (infile) {
        string cod, continut;
        int zi, luna, an;
        infile >> cod >> ws;
        getline(infile, continut);
        infile >> zi >> luna >> an;
        if (!infile) break;
        comentarii.push_back(Comentariu(cod, continut, Data(zi, luna, an)));
    }
    infile.close();
    return comentarii;
}

void salveazaComentarii(const vector<Comentariu>& comentarii) {
    ofstream outfile("shared/files/comentarii.txt");
    for (const auto& comentariu : comentarii) {
        outfile << comentariu.getCodArticol() << "\n" << comentariu.getContinut() << "\n"
                << comentariu.getData().getZi() << " " << comentariu.getData().getLuna() << " "
                << comentariu.getData().getAn() << "\n";
    }
    outfile.close();
}

vector<Articol> incarcaArticole() {
    vector<Articol> articole;
    ifstream infile("shared/files/articole.txt");
    int numar_articole;
    infile >> numar_articole;
    for (int i = 0; i < numar_articole; ++i) {
        string cod, titlu, continut;
        int love, like, dislike, numar_comentarii;
        infile >> cod >> ws;
        getline(infile, titlu);
        getline(infile, continut);
        infile >> love >> like >> dislike >> numar_comentarii;
        Articol articol(cod, titlu, continut);
        articole.push_back(articol);
    }
    infile.close();
    return articole;
}

void salveazaArticole(const vector<Articol>& articole) {
    ofstream outfile("shared/files/articole.txt");
    outfile << articole.size() << "\n";
    for (const auto& articol : articole) {
        outfile << articol.getCod() << "\n" << articol.getTitlu() << "\n" << articol.getContinut() << "\n"
                << articol.getLove() << "\n" << articol.getLike() << "\n" << articol.getDislike() << "\n"
                << articol.getComentarii().size() << "\n";
        for (const auto& comentariu : articol.getComentarii()) {
            outfile << comentariu.getCodArticol() << "\n" << comentariu.getContinut() << "\n"
                    << comentariu.getData().getZi() << " " << comentariu.getData().getLuna() << " "
                    << comentariu.getData().getAn() << "\n";
        }
    }
    outfile.close();
}

void afiseazaHelp() {
    cout << "Comenzi disponibile:\n";
    cout << "  help                         - Afiseaza acest mesaj\n";
    cout << "  adaugare_comentariu <cod> <continut>  - Adauga un comentariu\n";
    cout << "  vizualizare_comentarii <cod> - Vizualizeaza comentariile unui articol\n";
    cout << "  love_articol <cod>           - Adauga un love la un articol\n";
    cout << "  like_articol <cod>           - Adauga un like la un articol\n";
    cout << "  dislike_articol <cod>        - Adauga un dislike la un articol\n";
}

int main(int argc, char* argv[]) {
    vector<Comentariu> comentarii = incarcaComentarii();
    vector<Articol> articole = incarcaArticole();
    if (argc > 1) {
        string comanda = argv[1];
        if (comanda == "help") {
            afiseazaHelp();
        } else if (comanda == "adaugare_comentariu" && argc == 4) {
            string cod = argv[2];
            string continut = argv[3];
            Comentariu comentariu(cod, continut, Data(28, 6, 2024)); // Exemplu data
            comentarii.push_back(comentariu);
            for (auto& articol : articole) {
                if (articol.getCod() == cod) {
                    articol.adaugaComentariu(comentariu);
                    break;
                }
            }
            salveazaComentarii(comentarii);
            salveazaArticole(articole);
        } else if (comanda == "vizualizare_comentarii" && argc == 3) {
            string cod = argv[2];
            for (const auto& comentariu : comentarii) {
                if (comentariu.getCodArticol() == cod) {
                    cout << comentariu << "\n";
                }
            }
        } else if (comanda == "love_articol" && argc == 3) {
            string cod = argv[2];
            for (auto& articol : articole) {
                if (articol.getCod() == cod) {
                    articol.adaugaLove();
                    break;
                }
            }
            salveazaArticole(articole);
        } else if (comanda == "like_articol" && argc == 3) {
            string cod = argv[2];
            for (auto& articol : articole) {
                if (articol.getCod() == cod) {
                    articol.adaugaLike();
                    break;
                }
            }
            salveazaArticole(articole);
        } else if (comanda == "dislike_articol" && argc == 3) {
            string cod = argv[2];
            for (auto& articol : articole) {
                if (articol.getCod() == cod) {
                    articol.adaugaDislike();
                    break;
                }
            }
            salveazaArticole(articole);
        } else {
            cout << "Comanda invalida. Folositi 'help' pentru a vedea comenzile disponibile.\n";
        }
    } else {
        cout << "Comanda invalida. Folositi 'help' pentru a vedea comenzile disponibile.\n";
    }
    return 0;
}
