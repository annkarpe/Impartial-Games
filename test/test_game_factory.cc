#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<type_traits>
#include"../lib/game.h"
#include"../lib/play.h"
#include"../lib/game_factory.h"

class GameFactoryTest : public testing::Test {
public:
    GameFactory gf;
};

TEST_F(GameFactoryTest, RegisterGameAdsOneGameToGamesMap) {
    EXPECT_EQ(gf.titles_of_games().size(), 0);
    gf.register_game("nim", Nim::create);
    EXPECT_EQ(gf.titles_of_games().size(), 1);
}

TEST_F(GameFactoryTest, RegisterGameAdsCorrectGamesToGamesMap) {
    gf.register_game("chomp", Chomp::create);
    gf.register_game("nim", Nim::create);
    EXPECT_EQ(gf.titles_of_games()[0], "chomp");
    EXPECT_EQ(gf.titles_of_games()[1], "nim");
}

TEST_F(GameFactoryTest, UnregisterGameRemovesCorrectGame) {
    gf.register_game("nim", Nim::create);
    gf.register_game("chomp", Chomp::create);

    gf.unregister_game("nim");
    EXPECT_EQ(gf.titles_of_games().size(), 1);
    EXPECT_EQ(gf.titles_of_games()[0], "chomp");
}

TEST_F(GameFactoryTest, CreateGameCreatesInstanceOfGame) {
    gf.register_game("nim", Nim::create);
    
    std::unique_ptr<Game> g = gf.create_game("nim");
    EXPECT_TRUE(g != nullptr);
}

TEST_F(GameFactoryTest, CreateGameTrowsErrorWhenInputIsIncorrect) {
    EXPECT_THROW(gf.create_game("zxcv"), std::runtime_error);
}


