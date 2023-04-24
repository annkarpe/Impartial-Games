#ifndef PLAY
#define PLAY

#include"game.h"
#include"game_factory.h"
#include"user_input_handler.h"
#include<iostream>
#include<memory>
#include<cstdlib>
#include<string>
#include<fstream>
#include<chrono>

enum StartsFirst {Player, Computer};
enum Mode {PC, PP};

class Play {
    GameFactory& gf;
    UserInputHandler& uih;
public:
    Play(GameFactory& gfact, UserInputHandler& usih);

    std::unique_ptr<Game> g;
    int player = 0;
    void choose();
    void init();
    void one_move();
    void play();
    void ai_move();
    void register_g(const std::string &name, auto f);
    void pp_play();
    void pc_play(int starts);
};


#endif