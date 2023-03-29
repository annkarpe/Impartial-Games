#ifndef GAME_F
#define GAME_F

#include<string>
#include<map>
#include<memory>
#include<functional>
#include<stdexcept>

class Game;

class GameFactory {
    using create_callback
     = std::function<std::unique_ptr<Game>()>;    
    using callback_map = std::map<std::string, create_callback>;
    static callback_map games_map;
public:
    static void register_game(const std::string &name, create_callback cb);
    static void unregister_game(const std::string &name);
    static std::unique_ptr<Game> create_game(const std::string &name);
};

#endif
