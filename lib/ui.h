#pragma once
#include<iostream>
#include"nim.h"
#include"chomp.h"

class UI {
    Nim n;
    Chomp ch;
public:
    template <typename T>
    void print_board(T t);
};