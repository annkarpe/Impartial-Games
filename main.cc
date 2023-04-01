#include <iostream>

#include "lib/game.h"
#include "lib/game_factory.h"
#include "lib/play.h"
#include "lib/user_input_handler.h"
#include"src/game_factory.cc"
#include "src/game.cc"
#include "src/play.cc"
#include "src/user_input_handler.cc"

int main() {
    GameFactory gf;
    Play p;
    p.register_g("nim", Nim::create);
    p.register_g("chomp", Chomp::create);

    
    

    p.choose();
    p.init();

    p.play();

}
