#pragma once
#include<iostream>
#include<vector>
#include"nim.h"
#include"chomp.h"
#include"player.h"
#include"user_input_handler.h"

enum Mode{PP, PC};
enum StartsFirst{P, C};
enum ChosenGame {N, Ch};
//I know, that for testing purposes composition is a beter option
//but here we have a solid IS-A relationship 
//Should I finally choose an inheritence?
class ImpartialGame {
    Nim n;
    Chomp ch;
    ChosenGame chosen_game;
    UserInputHandler uih;
    Mode m;
    Player p1;
    Player p2;
    Player curr_player;
    StartsFirst sf;

public:
    void print_board();
// I don't really like that all methods which set user input,
// which can be incorrect return bool (is set/is not set).
// I want them to be void. At the same time I don't want to 
// have a logic. which checks input inside UserInputHandler.
    bool set_chosen_game(int n);
    ChosenGame get_chosen_game();
    bool set_mode(int n);
    Mode get_mode();
    bool set_starts_first(int n);
    StartsFirst get_starts_first();
    void congratulateWinner();
    void play();
};