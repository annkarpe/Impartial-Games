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
void Play::ai_move() {
    std::cout << g->to_string() << std::endl;
    std::vector<std::unique_ptr<Game>> ch = g->children();
    for (auto &c : ch) {
        if (!c->is_winning_pos()) {
            g = std::move(c);
            return;
        }
    }
    srand(time(NULL));
    int r = rand() % ch.size();
    g = std::move(ch[r]);
}

void Play::one_move() {
    std::cout << g->to_string() << std::endl;
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

void Play::pp_play() {
    while (g->any_moves_left()) {
        std::cout << "player " << player << " moves\n";                     
        one_move();
        player = !player;            
    }    

    std::cout << "player " << player << " wins!";  
}

void Play::pc_play(int player_starts) {
    int player_turn;
    while(g->any_moves_left()) {
        if (player_turn) {
            one_move();
        } else {
            ai_move();
        }
        std::cout << (player_turn ? "player moves\n" : "computer moves\n");
        if (!g->any_moves_left()) {
            std::cout << (player_turn ? "computer wins\n" : "player wins\n");
            break;
        }
        player_turn = !player_turn;
    }
}

void Play::play() {
    switch(std::stoi(uih.ask_mode())) {
        case Mode::PC:
            if (std::stoi(uih.ask_starts_first()) == StartsFirst::Player) {
                pc_play(StartsFirst::Player);
            } else {
                pc_play(StartsFirst::Computer);
            }
            break;
        case Mode::PP:
            pp_play();
            break;
    }
}

void Play::register_g(const std::string &name, auto f) {
    gf.register_game(name, f);
}