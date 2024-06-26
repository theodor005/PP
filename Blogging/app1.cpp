#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "shared/classes/Articol.hpp"
#include "shared/classes/Comentariu.hpp"
#include "shared/classes/Data.hpp"

std::vector<Articol> loadArticole() {
    std::vector<Articol> articole;
    std::ifstream infile("shared/files/articole.txt");
    if (infile) {
        int numar_articole;
        infile >> numar_articole;
        infile.ignore();
        for (int i = 0; i < numar_articole; ++i) {
            std::string cod, titlu, continut;
            int numar_love, numar_like, numar_dislike, numar_comentarii;
            getline(infile, cod);
            getline(infile, titlu);
            getline(infile, continut);
            infile >> numar_love >> numar_like >> numar_dislike >> numar_comentarii;
            infile.ignore();
            Articol articol(cod, titlu, continut);
            for (int j = 0; j < numar_comentarii; ++j) {
                std::string comentariu_continut;
                int zi, luna, an;
                getline(infile, comentariu_continut);
                infile >> zi >> luna >> an;
                infile.ignore(); // Ignore the newline character after the date
                Data data(zi, luna, an);
                Comentariu comentariu(cod, comentariu_continut, data);
                articol.addComentariu(comentariu);
            }
            articole.push_back(articol);
        }
    }
    return articole;
}

void saveArticole(const std::vector<Articol>& articole) {
    std::ofstream outfile("shared/files/articole.txt");
    outfile << articole.size() << "\n";
    for (const auto& articol : articole) {
        outfile << articol.getCod() << "\n" << articol.getTitlu() << "\n" << articol.getContinut() << "\n";
        outfile << articol.getNumarLove() << " " << articol.getNumarLike() << " " << articol.getNumarDislike() << " " << articol.getComentarii().size() << "\n";
        for (const auto& comentariu : articol.getComentarii()) {
            outfile << comentariu.getContinut() << "\n";
            outfile << comentariu.getData().getZi() << " " << comentariu.getData().getLuna() << " " << comentariu.getData().getAn() << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Invalid arguments\n";
        return 1;
    }

    std::string command = argv[1];
    std::vector<Articol> articole = loadArticole();

    if (command == "adaugare_articol" && argc == 5) {
        std::string cod = argv[2];
        std::string titlu = argv[3];
        std::string continut = argv[4];
        Articol newArticol(cod, titlu, continut);
        articole.push_back(newArticol);
        saveArticole(articole);
    } else if (command == "modificare_articol" && argc == 5) {
        std::string cod = argv[2];
        std::string titlu = argv[3];
        std::string continut = argv[4];
        for (auto& articol : articole) {
            if (articol.getCod() == cod) {
                articol.setTitlu(titlu);
                articol.setContinut(continut);
                break;
            }
        }
        saveArticole(articole);
    } else {
        std::cerr << "Invalid command\n";
    }

    return 0;
}
