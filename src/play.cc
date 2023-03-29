#include "../lib/game.h"
#include "../lib/play.h"
#include "../lib/game_factory.h"
#include "../lib/user_input_handler.h"


//can cause memory licks
//Games avilable: cout from file
void Play::choose() {
    std::cout << "Games avilable:\n";
    std::ifstream f;
    f.open("games.txt");
    if (!f) {
        std::cout << "Unable to open the file";
    }
    std::string str;
    while (std::getline(f, str)) {
        std::cout << str << '\n';
    }
    std::string name = uih.ask_game();
    g = gf.create_game(name);

    std::string ignore_newline;
    std::getline(std::cin, ignore_newline);
}

void Play::init() {
    std::cout << "initial board position?\n";
    std::string desc;
    std::getline(std::cin, desc);
    g->from_string(desc);
}

void Play::one_move() {
    std::cout << g->to_string() << std::endl;
    std::cout << "player " << player << " moves\n";
    player = !player;
    std::string desc;
    std::getline(std::cin, desc);
    bool ok = g->move(desc);
    while (!ok) {
        std::cout << "bad move!\n";
        std::cout << g->help() << std::endl;
        std::getline(std::cin, desc);
        ok = g->move(desc);
    }
}

void Play::play() {
    while (g->any_moves_left()) {
        one_move();
    }

    std::cout << "player " << player << " loses!";
}

