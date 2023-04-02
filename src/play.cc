#include "../lib/game.h"
#include "../lib/play.h"
#include "../lib/game_factory.h"
#include "../lib/user_input_handler.h"

Play::Play(GameFactory& gfact, UserInputHandler& usih)
    :gf(gfact), uih(usih) {}

void Play::choose() {
    std::cout << "Games available:\n";
    auto titles = gf.titles_of_games();
    for (auto &i : titles) {
        std::cout << i << std::endl;
    }
    std::string name = uih.ask_game();
    g = gf.create_game(name);
}

void Play::init() {
    g->from_string(uih.ask_init());
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

void Play::register_g(const std::string &name, auto f) {
    gf.register_game(name, f);
}
