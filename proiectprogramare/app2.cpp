#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "shared/classes/Articol.cpp"  // Include header-ul pentru Articol

using namespace std;

// Funcție pentru încărcarea articolelor din fișier
vector<Articol> incarcaArticole() {
    vector<Articol> articole;
    ifstream infile("shared/files/articole.txt");
    if (!infile) {
        cerr << "Nu s-a putut deschide fisierul pentru citire: shared/files/articole.txt" << endl;
        return articole;
    }

    int numar_articole;
    infile >> numar_articole;
    infile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoră restul liniei după citirea numărului

    for (int i = 0; i < numar_articole; ++i) {
        int id, love, like, dislike;
        string titlu, descriere;
        infile >> id;
        infile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoră restul liniei după citirea id-ului
        getline(infile, titlu);
        getline(infile, descriere);
        infile >> love >> like >> dislike;

        Articol articol(id, titlu, descriere, like, dislike, love);
        articole.push_back(articol);
    }

    infile.close();
    return articole;
}

// Funcție pentru salvarea articolelor în fișier
void salveazaArticole(const vector<Articol>& articole) {
    ofstream outfile("shared/files/articole.txt");
    if (!outfile) {
        cerr << "Nu s-a putut deschide fisierul pentru scriere: shared/files/articole.txt" << endl;
        return;
    }

    outfile << articole.size() << endl; // Prima linie conține numărul de articole

    for (const auto& articol : articole) {
        outfile << articol.getId() << endl;
        outfile << articol.getTitlu() << endl;
        outfile << articol.getDescriere() << endl;
        outfile << articol.getNumarLove() << " " << articol.getNumarLike() << " " << articol.getNumarDislike() << endl;
    }

    outfile.close();
}

// Funcție pentru afișarea mesajului de ajutor
void afiseazaHelp() {
    cout << "Comenzi disponibile:\n";
    cout << "  help                         - Afiseaza acest mesaj\n";
    cout << "  love_articol <id>           - Adauga un love la un articol\n";
    cout << "  like_articol <id>           - Adauga un like la un articol\n";
    cout << "  dislike_articol <id>        - Adauga un dislike la un articol\n";
}

int main(int argc, char* argv[]) {
    vector<Articol> articole = incarcaArticole();  // Încarcă articolele din fișier

    if (argc > 1) {
        string comanda = argv[1];
        if (comanda == "help") {
            afiseazaHelp();
        } else if (comanda == "love_articol" && argc == 3) {
            int id = stoi(argv[2]);
            bool articolGasit = false;
            for (auto& articol : articole) {
                if (articol.getId() == id) {
                    articol.adaugaLove();
                    articolGasit = true;
                    break;
                }
            }
            if (articolGasit) {
                salveazaArticole(articole);
            } else {
                cout << "Articol cu ID-ul " << id << " nu a fost gasit.\n";
            }
        } else if (comanda == "like_articol" && argc == 3) {
            int id = stoi(argv[2]);
            bool articolGasit = false;
            for (auto& articol : articole) {
                if (articol.getId() == id) {
                    articol.adaugaLike();
                    articolGasit = true;
                    break;
                }
            }
            if (articolGasit) {
                salveazaArticole(articole);
            } else {
                cout << "Articol cu ID-ul " << id << " nu a fost gasit.\n";
            }
        } else if (comanda == "dislike_articol" && argc == 3) {
            int id = stoi(argv[2]);
            bool articolGasit = false;
            for (auto& articol : articole) {
                if (articol.getId() == id) {
                    articol.adaugaDislike();
                    articolGasit = true;
                    break;
                }
            }
            if (articolGasit) {
                salveazaArticole(articole);
            } else {
                cout << "Articol cu ID-ul " << id << " nu a fost gasit.\n";
            }
        } else {
            cout << "Comanda invalida. Folositi 'help' pentru a vedea comenzile disponibile.\n";
        }
    } else {
        cout << "Comanda invalida. Folositi 'help' pentru a vedea comenzile disponibile.\n";
    }

    return 0;
}
