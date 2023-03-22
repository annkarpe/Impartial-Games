#include<iostream>
#include"../lib/ui.h"

//as a parameter an instance of Nim or Chomp should be passed
template <typename T>
void UI::print_board(T t) {
    std::string elem = t.get_elem();
    std::string spec_elem;
    if (t.get_spec_elem()) {
        spec_elem = t.get_spec_elem();
    } else {
        spec_elem = elem;
    }
    int i = 0;
    for (i; i < t->rows.size(); i++) {
        std::cout << "Row: " << i << ":";
        for (int j = 0; j < t->rows[i]; j++) {
            std::cout << elem;
        }
        std::cout << '\n';
    }
    std::cout << spec_elem;
    for (int j = 1; j < t->rows[i]; j++) {
        std::cout << elem;
    }
}
