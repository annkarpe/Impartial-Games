#include <iostream>

#include "lib/game.h"
#include "lib/game_factory.h"
#include "lib/play.h"
#include "lib/user_input_handler.h"
/**/
#include"src/game_factory.cc"
#include "src/game.cc"
#include "src/play.cc"
#include "src/user_input_handler.cc"

int main() {
    GameFactory gf;
    gf.register_game("nim", Nim::create);
    gf.register_game("chomp", Chomp::create);

    Play p;
    

    p.choose();
    p.init();

    p.play();

}


// def of mathematical game
// make play class extensible using factory
/*
Play p;
p.register("nim", Nim::create) static method of a nim class



*/