#include"../lib/user_input_handler.h"

std::string UserInputHandler::ask_game() const {
    std::cout << "Enter the name of the game you would like to play:\n";
    std::string choice;
    std::cin >> choice;
    std::string ignore;
    std::getline(std::cin, ignore);
    return choice;
}

std::string UserInputHandler::ask_init() const {
    std::cout << "Initial board position?\n";
    std::string desc;
    std::getline(std::cin, desc);
    return desc;
}

std::string UserInputHandler::ask_mode() const {
    std::cout << "If you would like to play with computer press 0. If you want to play with another player, press 1:\n";
    std::string choice;
    std::cin >> choice;
    std::string ignore;
    std::getline(std::cin, ignore);
    return choice;
}
