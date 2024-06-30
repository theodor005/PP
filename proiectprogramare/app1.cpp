#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include "shared/classes/Articol.cpp"
#include "shared/classes/Comentariu.cpp"
#include "shared/classes/Data.cpp"
using namespace std;

// Funcție pentru citirea articolelor dintr-un fișier
vector<Articol> citesteArticoleDinFisier(const string& numeFisier) {
    vector<Articol> articole;
    ifstream infile(numeFisier);

    if (!infile.is_open()) {
        cerr << "Nu s-a putut deschide fisierul: " << numeFisier << endl;
        return articole;
    }

    int numarArticole;
    infile >> numarArticole;
    infile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoră restul liniei după citirea numărului

    for (int i = 0; i < numarArticole; ++i) {
        int id, numar_like, numar_dislike, numar_love;
        string titlu, descriere;

        infile >> id;
        infile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoră restul liniei după citirea id-ului
        getline(infile, titlu);
        getline(infile, descriere);
        infile >> numar_like >> numar_dislike >> numar_love;
        infile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoră restul liniei după citirea like/dislike/love

        if (!infile) break;

        Articol articol(id, titlu, descriere, numar_like, numar_dislike, numar_love);
        articole.push_back(articol);
    }

    infile.close();
    return articole;
}

// Funcție pentru scrierea articolelor într-un fișier
void scrieArticoleInFisier(const string& numeFisier, const vector<Articol>& articole) {
    ofstream outfile(numeFisier);

    if (!outfile.is_open()) {
        cerr << "Nu s-a putut deschide fisierul pentru scriere: " << numeFisier << endl;
        return;
    }

    outfile << articole.size() << endl; // Prima linie conține numărul de articole

    for (const auto& articol : articole) {
        outfile << articol.getId() << endl;
        outfile << articol.getTitlu() << endl;
        outfile << articol.getDescriere() << endl;
        outfile << articol.getNumarLike() << " " << articol.getNumarDislike() << " " << articol.getNumarLove() << endl;
    }

    outfile.close();
}

void afiseazaHelp() {
    cout << "Comenzi disponibile:\n";
    cout << "  help                         - Afiseaza acest mesaj\n";
    cout << "  vizualizare_articole        - Afiseaza toate articolele\n";
    cout << "  adaugare_articol <id> <titlu> <descriere>  - Adauga un articol\n";
    cout << "  stergere_articol <id>        - Sterge un articol\n";
    cout << "  modificare_articol <id> <titlu> <descriere> - Modifica un articol\n";
}

int main(int argc, char* argv[]) {
    vector<Articol> articole = citesteArticoleDinFisier("shared/files/articole.txt");

    if (argc > 1) {
        string comanda = argv[1];

        if (comanda == "help") {
            afiseazaHelp();
        } else if (comanda == "vizualizare_articole") {
            for (const auto& articol : articole) {
                cout << "ID: " << articol.getId() << "\n";
                cout << "Titlu: " << articol.getTitlu() << "\n";
                cout << "Descriere: " << articol.getDescriere() << "\n";
                cout << "Like-uri: " << articol.getNumarLike() << "\n";
                cout << "Dislike-uri: " << articol.getNumarDislike() << "\n";
                cout << "Love-uri: " << articol.getNumarLove() << "\n";
                cout << "------------------------\n";
            }
        } else if (comanda == "adaugare_articol" && argc == 5) {
            int id = stoi(argv[2]);
            string titlu = argv[3];
            string descriere = argv[4];
            Articol articol(id, titlu, descriere);
            articole.push_back(articol);
            scrieArticoleInFisier("shared/files/articole.txt", articole);
        } else if (comanda == "stergere_articol" && argc == 3) {
            int id = stoi(argv[2]);
            articole.erase(remove_if(articole.begin(), articole.end(),
                                     [id](const Articol& articol) { return articol.getId() == id; }),
                           articole.end());
            scrieArticoleInFisier("shared/files/articole.txt", articole);
        } else if (comanda == "modificare_articol" && argc == 5) {
            int id = stoi(argv[2]);
            string titlu = argv[3];
            string descriere = argv[4];
            for (auto& articol : articole) {
                if (articol.getId() == id) {
                    articol.setTitlu(titlu);
                    articol.setDescriere(descriere);
                    break;
                }
            }
            scrieArticoleInFisier("shared/files/articole.txt", articole);
        } else {
            cout << "Comanda invalida. Folositi 'help' pentru a vedea comenzile disponibile.\n";
        }
    } else {
        cout << "Comanda invalida. Folositi 'help' pentru a vedea comenzile disponibile.\n";
    }

    return 0;
}
