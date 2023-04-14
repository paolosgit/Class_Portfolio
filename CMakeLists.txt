cmake_minimum_required(VERSION 3.23)
project(CS3Aportfolio)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS3Aportfolio main.cpp Snake/Food.cpp Snake/Food.h Snake/SingleCell.cpp Snake/SingleCell.h Snake/SnakeBody.cpp Snake/SnakeBody.h PokerAnalysis/suitEnum.h PokerAnalysis/Scores.h PokerAnalysis/rankEnum.h PokerAnalysis/Card.cpp PokerAnalysis/Card.h PokerAnalysis/CardHand.cpp PokerAnalysis/CardHand.h PokerAnalysis/Deck.cpp PokerAnalysis/Deck.h PokerAnalysis/CardHandScorer.cpp PokerAnalysis/CardHandScorer.h PokerAnalysis/PokerScore.cpp PokerAnalysis/PokerScore.h DrawCard/CardVisual.cpp DrawCard/CardVisual.h Pong/Paddle.cpp Pong/Paddle.h Pong/bounce.cpp Pong/bounce.h TopHatGuy/TopHatGuy.cpp TopHatGuy/TopHatGuy.h BouncingBall/BouncingBall.cpp BouncingBall/BouncingBall.h  WindowStates.cpp WindowStates.h)

target_link_libraries(CS3Aportfolio sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

