#ifndef GAME_F
#define GAME_F

#include<string>
#include<vector>
#include<map>
#include<memory>
#include<functional>
#include<stdexcept>

#include"game.h"

class Game;

class GameFactory {
protected:
    using create_callback
     = std::function<std::unique_ptr<Game>()>;    
    using callback_map = std::map<std::string, create_callback>;
    callback_map games_map;
public:
    void register_game(const std::string &name, create_callback cb);
    void unregister_game(const std::string &name);
    std::unique_ptr<Game> create_game(const std::string &name);
    std::vector<std::string> titles_of_games();
};

#endif
