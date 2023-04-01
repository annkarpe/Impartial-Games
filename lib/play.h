#ifndef PLAY
#define PLAY

#include"game.h"
#include"game_factory.h"
#include"user_input_handler.h"
#include<iostream>
#include<memory>
#include<string>
#include<fstream>

class Play {
    GameFactory gf;
    UserInputHandler uih;
public:
    std::unique_ptr<Game> g;
    int player = 0;
    void choose();
    void init();
    void one_move();
    void play();
    void register_g(const std::string &name, auto f);
};


#endif