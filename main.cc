#include <iostream>
#include "lib/game.h"
#include "src/play.cc"
#include "src/game.cc"

int main() {

    Play p;

    p.choose();
    p.init();

    p.play();

}


// def of mathematical game
// make play class extensible using factory
/*
Play p;
p.register("nim", Nim::create) static method of a nim class



*/