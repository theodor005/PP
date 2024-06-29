#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "shared/classes/Articol.cpp"
#include "shared/classes/Comentariu.cpp"
#include "shared/classes/Data.cpp"

using namespace std;

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
        for (int j = 0; j < numar_comentarii; ++j) {
            string cod_comentariu, continut_comentariu;
            int zi, luna, an;
            infile >> cod_comentariu >> ws;
            getline(infile, continut_comentariu);
            infile >> zi >> luna >> an;
            articol.adaugaComentariu(Comentariu(cod_comentariu, continut_comentariu, Data(zi, luna, an)));
        }
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
    cout << "  vizualizare_articole        - Afiseaza toate articolele\n";
    cout << "  adaugare_articol <cod> <titlu> <continut>  - Adauga un articol\n";
    cout << "  stergere_articol <cod>      - Sterge un articol\n";
    cout << "  modificare_articol <cod> <titlu> <continut> - Modifica un articol\n";
}

int main(int argc, char* argv[]) {
    vector<Articol> articole = incarcaArticole();
    if (argc > 1) {
        string comanda = argv[1];
        if (comanda == "help") {
            afiseazaHelp();
        } else if (comanda == "vizualizare_articole") {
            for (const auto& articol : articole) {
                cout << articol << "\n";
            }
        } else if (comanda == "adaugare_articol" && argc == 5) {
            string cod = argv[2];
            string titlu = argv[3];
            string continut = argv[4];
            Articol articol(cod, titlu, continut);
            articole.push_back(articol);
            salveazaArticole(articole);
        } else if (comanda == "stergere_articol" && argc == 3) {
            string cod = argv[2];
            articole.erase(remove_if(articole.begin(), articole.end(),
                                     [&cod](const Articol& articol) { return articol.getCod() == cod; }),
                           articole.end());
            salveazaArticole(articole);
        } else if (comanda == "modificare_articol" && argc == 5) {
            string cod = argv[2];
            string titlu = argv[3];
            string continut = argv[4];
            for (auto& articol : articole) {
                if (articol.getCod() == cod) {
                    articol = Articol(cod, titlu, continut);
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
