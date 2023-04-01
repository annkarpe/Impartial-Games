#include"../lib/game_factory.h"

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
        throw std::runtime_error("Unknown game");
    }
}

std::vector<std::string> GameFactory::titles_of_games() {
    std::vector<std::string> v;
    for (auto kv : games_map) {
        v.push_back(kv.first);
    }
    return v;
}



