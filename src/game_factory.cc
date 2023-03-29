#include"../lib/game_factory.h"

GameFactory::callback_map GameFactory::games_map;

void GameFactory::register_game(const std::string &name, create_callback cb) {
    games_map[name] = cb;
}
void GameFactory::unregister_game(const std::string &name) {
    games_map.erase(name);
}
std::unique_ptr<Game> GameFactory::create_game(const std::string &name) {
    auto it = games_map.find(name);
    if (it != games_map.end()) {
        return it->second();
    } else {
        // it should be handled 
        throw std::runtime_error("Unknown game");
    }
}



