#include<iostream>
#include"../lib/user_input_handler.h"

std::string UserInputHandler::ask_name() {
    std::string n;
    std::cout << "Name: \n";
    std::cin >> n;
    return n;
}
std::vector<int> UserInputHandler::ask_heaps_nim() {
    int num;
    int n;
    std::vector<int> v;

    std::cout << "Enter number of rows\n";
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        std::cout << "Enter number of elements in the row " << i+1 << '\n';
        std::cin >> n;
        v.push_back(n);
    }
    return v;
}
std::vector<int> UserInputHandler::ask_heaps_chomp() {
    int num;
    int n;
    std::vector<int> v;

    std::cout << "Enter number of rows\n";
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        v.push_back(num);
    }
    return v;
}
std::pair<int, int> UserInputHandler::ask_move() {
    int row;
    int el;
    std::cout << "From which row would you like to take an element?\n";
    std::cin >> row;
    std::cout << "How many elements would you like to take?\n";
    std::cin >> el;
    return std::pair<int, int> {row, el};
    
}
int UserInputHandler::ask_mode() {
    int m;
    std::cout << "If you want to play with other player press 0. "
        "If you want to play with computer, press 1\n";
    std::cin >> m;
    return m;
}
int UserInputHandler::ask_game() {
    int m;
    std::cout << "If you want to play Nim press 0. "
        "If you want to play Chomp, press 1\n";
    std::cin >> m;
    return m;
}
int UserInputHandler::ask_starts_first() {
    int n;
    std::cout << "If you want to make the first move, press 0. "
        "If you want computer to start first press 1\n";
    std::cin >> n;
    return n;
}
