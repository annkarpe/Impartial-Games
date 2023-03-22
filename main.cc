#include<iostream>
#include<vector>
#include"lib/impartial_game.h"
#include"lib/nim.h"
#include"lib/chomp.h"
#include"lib/player.h"
#include"lib/user_input_handler.h"
#include"lib/ui.h"

int main() {
    Nim n;
    UI ui;
    
    n.set_rows(std::vector<int>{1, 2});
    n.gen_possible_moves();
    std::pair<int, int> p = n.get_best_move();
    std::cout << p.first << " " << p.second << '\n';
    std::vector<int> v = n.get_rows();
    for (auto i : v) {
        std::cout << i;
    }
    std::cout << std::endl;
     
    n.print();
    //causes linking error
    //ui.print_board(n);
    
   /* */


    return 0;
}