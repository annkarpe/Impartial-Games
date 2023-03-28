#include "../lib/game.h"
#include "../lib/play.h"
#include<iostream>
#include<memory>

//can cause memory licks
void Play::choose() {
    std::cout << "which game [nim/chomp]?\n";
    std::string choice;
    std::cin >> choice;
    if (choice == "nim") {
        g = std::make_unique<Nim>();
    } else if (choice == "chomp") {
        g = std::make_unique<Chomp>();
    }
    std::string ignore_newline;
    std::getline(std::cin, ignore_newline);
}

void Play::init() {
    std::cout << "initial board position?\n";
    std::string desc;
    std::getline(std::cin, desc);
    g->from_string(desc);
}

void Play::one_move() {
    std::cout << g->to_string() << std::endl;
    std::cout << "player " << player << " moves\n";
    player = !player;
    std::string desc;
    std::getline(std::cin, desc);
    bool ok = g->move(desc);
    while (!ok) {
        std::cout << "bad move!\n";
        std::cout << g->help() << std::endl;
        std::getline(std::cin, desc);
        ok = g->move(desc);
    }
}

void Play::play() {
    while (g->any_moves_left()) {
        one_move();
    }

    std::cout << "player " << player << " loses!";
}

