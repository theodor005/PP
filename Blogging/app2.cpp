#include <iostream>
#include <fstream>
#include <vector>
#include "shared/classes/Articol.hpp"
#include "shared/classes/Comentariu.hpp"
#include "shared/classes/Data.hpp"

// Funcții de încărcare și salvare a articolelor
std::vector<Articol> loadArticole();
void saveArticole(const std::vector<Articol>& articole);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Invalid arguments\n";
        return 1;
    }

    std::string command = argv[1];
    std::vector<Articol> articole = loadArticole();

    if (command == "adaugare_comentariu" && argc == 4) {
        std::string cod = argv[2];
        std::string continut = argv[3];
        Data data(23, 6, 2024); // Exemplu de dată
        Comentariu newComentariu(cod, continut, data);
        for (auto& articol : articole) {
            if (articol.getCod() == cod) {
                articol.addComentariu(newComentariu);
                break;
            }
        }
        saveArticole(articole);
    } else if (command == "vizualizare_comentarii" && argc == 3) {
        std::string cod = argv[2];
        for (const auto& articol : articole) {
            if (articol.getCod() == cod) {
                for (const auto& comentariu : articol.getComentarii()) {
                    std::cout << comentariu << "\n";
                }
                break;
            }
        }
    } else if (command == "love_articol" && argc == 3) {
        std::string cod = argv[2];
        for (auto& articol : articole) {
            if (articol.getCod() == cod) {
                articol.addLove();
                break;
            }
        }
        saveArticole(articole);
    } else if (command == "like_articol" && argc == 3) {
        std::string cod = argv[2];
        for (auto& articol : articole) {
            if (articol.getCod() == cod) {
                articol.addLike();
                break;
            }
        }
        saveArticole(articole);
    } else if (command == "dislike_articol" && argc == 3) {
        std::string cod = argv[2];
        for (auto& articol : articole) {
            if (articol.getCod() == cod) {
                articol.addDislike();
                break;
            }
        }
        saveArticole(articole);
    } else if (command == "vizualizare_articol" && argc == 3) {
        std::string cod = argv[2];
        for (const auto& articol : articole) {
            if (articol.getCod() == cod) {
                std::cout << articol << "\n";
                break;
            }
        }
    } else {
        std::cerr << "Invalid command\n";
    }

    return 0;
}
