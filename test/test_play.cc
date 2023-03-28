#include<gtest/gtest.h>
#include"../lib/play.h"
#include"../lib/game.h"


class PlayTest : public testing::Test {
public:
    Play p;
};


/*
TEST_F(PlayTest, choose_nim_game) {
    std::istringstream iss("nim");
    std::cin.rdbuf(iss.rdbuf());
    p.choose();
    ASSERT_TRUE(dynamic_cast<Nim*>(p.g.get()) != nullptr);
}
*/


