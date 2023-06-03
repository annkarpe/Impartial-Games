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


extern "C" {
    GameFactory *new_GameFactory() {
        return new GameFactory;
    };

    UserInputHandler *new_UserInputHandler() {
        return new UserInputHandler;
    }

    Play *new_Play(GameFactory *new_gf, UserInputHandler *new_uih) {
        Play *new1_Play = new Play(*new_gf, *new_uih);
        new1_Play->register_g("nim", Nim::create);
        new1_Play->register_g("chomp", Chomp::create);
        new1_Play->choose();
        new1_Play->init();
        new1_Play->play();
        return new1_Play;
    }

    void Play_choose(Play *new_p) {
        new_p->choose();
    }

    void Play_init(Play *new_p) {
        new_p->init();
    }

    void Play_play(Play *new_p) {
        new_p->play();
    }

    void run() {
        GameFactory gf;
        UserInputHandler uih;
        Play p(gf, uih);
        p.register_g("nim", Nim::create);
        p.register_g("chomp", Chomp::create);

        p.choose();
        p.init();

        p.play();
    }

    void delete_Play(Play *new_p) {
        delete new_p;
    }

    void delete_GameFactory(GameFactory *new_gf) {
        delete new_gf;
    }

    void delete_UserInputHandler(UserInputHandler *new_uih) {
        delete new_uih;
    }
}