#ifndef PLAY
#define PLAY

#include"game.h"

//create another class that wraps play Play should run on sstream
//or mock cout
//or create iostream, ostream as fields, create constructor
class Play {
public:
    std::unique_ptr<Game> g;
    int player = 0;
    void choose();
    void init();
    void one_move();
    void play();
};


#endif