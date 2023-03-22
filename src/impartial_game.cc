#include<iostream>
#include"../lib/impartial_game.h"
#include"../lib/player.h"

void ImpartialGame::print_board() {

};

bool ImpartialGame::set_chosen_game(int n) {
    if (n == 0) {
        chosen_game = N;
        return true;
    } else if (n == 1) {
        chosen_game = Ch;
        return true;
    } else {
        std::cout << "Incorrect input. Press only 0 or 1\n";
        return false;
    }
}

ChosenGame ImpartialGame::get_chosen_game() {
    return chosen_game;
}

bool ImpartialGame::set_mode(int n) {
    if (n == 0) {
        m = PP;
        return true;
    } else if (n == 1) {
        m = PC;
        return true;
    } else {
        std::cout << "Incorrect input. Press only 0 or 1\n";
        return false;
    }
}

Mode ImpartialGame::get_mode() {
    return m;
}

bool ImpartialGame::set_starts_first(int n) {
    if (n == 0) {
        sf = P;
        return true;
    } else if (n == 1) {
        sf = C;
        return true;
    } else {
        std::cout << "Incorrect input. Press only 0 or 1\n";
        return false;
    }
}

StartsFirst ImpartialGame::get_starts_first() {
    return sf;
};

void ImpartialGame::congratulateWinner() {
    std::cout << "The winner is " << curr_player.get_name() << "!";
}

void ImpartialGame::play() {
    
};