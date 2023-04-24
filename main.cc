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
    UserInputHandler uih;
    Play p(gf, uih);
    p.register_g("nim", Nim::create);
    p.register_g("chomp", Chomp::create);

    p.choose();
    p.init();

    p.play();
}


/*
gcovr --html --output=coverage.html
lcov --directory . --capture --output-file coverage.info
genhtml coverage.info --output-directory coverage_html
*/