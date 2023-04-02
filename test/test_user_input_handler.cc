#include"../lib/user_input_handler.h"
#include <gtest/gtest.h>
#include <sstream>

class UserInputHandlerTest : public testing::Test {
public:
    UserInputHandler uih;
};

TEST_F(UserInputHandlerTest, GameNameReturnedTheSameAsInputed) {
    std::stringstream inp_str("nim\n");
    std::cin.rdbuf(inp_str.rdbuf());
    std::string g = uih.ask_game();
    EXPECT_EQ(g, "nim");
}

TEST_F(UserInputHandlerTest, InitialPositionReturnedTheSameAsInputed) {
    std::stringstream inp_str("4 5 6");
    std::cin.rdbuf(inp_str.rdbuf());
    std::string g = uih.ask_init();
    EXPECT_EQ(g, "4 5 6");
}