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

void Play::play() {
    if (uih.ask_mode() == "0") {
        std::cout << g->to_string() << std::endl;
        if (uih.ask_starts_first() == "0") {
            while(g->any_moves_left()) {
                one_move(); 
                std::cout << "player moves\n";              
                if(!g->any_moves_left()) {
                    std::cout << "computer wins\n"; 
                }
                if(g->any_moves_left()) {
                    ai_move();
                    std::cout << "computer moves\n";                  
                    if(!g->any_moves_left()) {
                        std::cout << "player wins\n"; 
                    }                 
                }
            }  
        } else {
            while(g->any_moves_left()) {
                ai_move(); 
                std::cout << "computer moves\n";              
                if(!g->any_moves_left()) {
                    std::cout << "player wins\n"; 
                }
                if(g->any_moves_left()) {
                    one_move();
                    std::cout << "player moves\n";                  
                    if(!g->any_moves_left()) {
                        std::cout << "computer wins\n"; 
                    }                 
                }
            }            
        }
    } else {
        while (g->any_moves_left()) {
            std::cout << "player " << player << " moves\n";                     
            one_move();
            player = !player;            
            
        }    
        std::cout << "player " << player << " wins!";            
    }
}

void Play::register_g(const std::string &name, auto f) {
    gf.register_game(name, f);
}
