#include <iostream>
#include "Snake/SnakeBody.h"
#include "Snake/Food.h"
#include "PokerAnalysis/Deck.h"
#include "PokerAnalysis/CardHand.h"
#include "PokerAnalysis/CardHandScorer.h"
#include "DrawCard/CardVisual.h"
#include "TopHatGuy/TopHatGuy.h"
#include "Pong/bounce.h"
#include "Pong/Paddle.h"
#include "BouncingBall/BouncingBall.h"
#include "WindowStates.h"
#include "SFML/Graphics.hpp"

int main() {
    sf::VideoMode videoMode(2040, 1260, 32);
    sf::RenderWindow window(videoMode, "SFML Portfolio");
    window.setFramerateLimit(25);
    WindowStates windowStates;


    //////////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////
    /////////////////////////////////////////
    //////////////////////////////////////////
    //SNAKE PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////
    SnakeBody snake(videoMode);
    Food food(videoMode);

    sf::Font font;
    font.loadFromFile("Fonts/SpaceMission-rgyw9.otf");

    sf::Text score;
    score.setFont(font);
    std::string scoreNum;
    scoreNum = std::to_string(snake.getLength()-1);
    score.setString("SCORE: " + scoreNum);
    score.setCharacterSize(50);
    score.setPosition(50, 0);


    sf::RectangleShape topBorder;
    topBorder.setSize({(float)videoMode.width, 5});
    topBorder.setPosition(0, 55);


    sf::Text restart;
    restart.setFont(font);
    restart.setString("RESTART");
    restart.setCharacterSize(200);
    restart.setPosition(600, 600);
    restart.setFillColor(sf::Color::Yellow);


    sf::Texture bioBackgroundTexture;
    bioBackgroundTexture.loadFromFile("Images/background.png");
    sf::Sprite bioBackground;
    bioBackground.setTexture(bioBackgroundTexture);
    bioBackground.setPosition(0, 60);
    bioBackground.setScale(1.8, 1.25);
    bioBackground.setColor(sf::Color(255,255,255,128));
    //////////////////////////////////////////
    //SNAKE PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////





    //////////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////
    //POKER ANALYSIS PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////
    float trialNum = 650000; //number of trials

    PokerScore pScore;
    for (int i = 0; i < trialNum; ++i) {
        Deck deck;
        CardHand hand1;
        CardHand hand2;
        CardHand hand3;
        CardHand hand4;
        CardHand hand5;


        for (int i = 0; i < 5; ++i) {
            hand1.addCard(deck);
            hand2.addCard(deck);
            hand3.addCard(deck);
            hand4.addCard(deck);
            hand5.addCard(deck);
        }

        PokerScore temp = CardHandScorer::scoreHand(hand1);
        pScore += temp;
    }


    std::cout << pScore; //prints out all the totals in the terminal


    //VISUAL OUTPUT
    sf::Font openSans;
    openSans.loadFromFile("fonts/OpenSans-Bold.ttf");

    sf::Text prob;   //There is only one text obj that says "Probability:" and I just move it to 10 different locations
    prob.setFont(openSans); //while displaying
    prob.setString("Probability:");
    prob.setCharacterSize(27);
    prob.setFillColor(sf::Color::Black);

    sf::Text num;   //same goes with for the text obj of the acutal number, this time while also changing the number
    num.setFont(openSans); // itself
    std::string s;
    num.setString(s);
    num.setCharacterSize(27);
    num.setFillColor(sf::Color::Black);


    //Creating text and card objects for royal flush
    sf::Text royalFlush_text;
    royalFlush_text.setFont(openSans);
    royalFlush_text.setString("Royal Flush:");
    royalFlush_text.setPosition({50,100});
    royalFlush_text.setCharacterSize(30);
    royalFlush_text.setFillColor(sf::Color::Black);
    CardVisual ROYALFLUSH_ace(HEARTS, ACE, 250, 70);
    CardVisual ROYALFLUSH_king(HEARTS, KING, 325, 70);
    CardVisual ROYALFLUSH_queen(HEARTS, QUEEN, 400, 70);
    CardVisual ROYALFLUSH_jack(HEARTS, JACK, 475, 70);
    CardVisual ROYALFLUSH_ten(HEARTS, TEN, 550, 70);


    //Creating text and card objects for straight flush
    sf::Text straightFlush_text;
    straightFlush_text.setFont(openSans);
    straightFlush_text.setString("Straight Flush:");
    straightFlush_text.setPosition({50,300});
    straightFlush_text.setCharacterSize(25);
    straightFlush_text.setFillColor(sf::Color::Black);
    CardVisual STRAIGHTFLUSH_2(SPADES, TWO, 250, 270);
    CardVisual STRAIGHTFLUSH_3(SPADES, THREE, 325, 270);
    CardVisual STRAIGHTFLUSH_4(SPADES, FOUR, 400, 270);
    CardVisual STRAIGHTFLUSH_5(SPADES, FIVE, 475, 270);
    CardVisual STRAIGHTFLUSH_6(SPADES, SIX, 550, 270);



    //Creating text and card objects for 4 of a kind
    sf::Text fourKind_text;
    fourKind_text.setFont(openSans);
    fourKind_text.setString("Four of a Kind:");
    fourKind_text.setPosition({50,500});
    fourKind_text.setCharacterSize(25);
    fourKind_text.setFillColor(sf::Color::Black);
    CardVisual FOURKIND_CLUBS(CLUBS, EIGHT, 250, 470);
    CardVisual FOURKIND_HEARTS(HEARTS, EIGHT, 325, 470);
    CardVisual FOURKIND_DIAMONDS(DIAMONDS, EIGHT, 400, 470);
    CardVisual FOURKIND_SPADES(SPADES, EIGHT, 475, 470);
    CardVisual FOURKIND_ODD(HEARTS, TWO, 550, 470);



    //Creating text and card objects for royal full house
    sf::Text fullHouse_text;
    fullHouse_text.setFont(openSans);
    fullHouse_text.setString("Full House:");
    fullHouse_text.setPosition({50,700});
    fullHouse_text.setCharacterSize(30);
    fullHouse_text.setFillColor(sf::Color::Black);
    CardVisual FULLHOUSE_DIAMONDSACE(DIAMONDS, ACE, 250, 670);
    CardVisual FULLHOUSE_SPADESFIVE(SPADES, FIVE, 325, 670);
    CardVisual FULLHOUSE_SPADESACE(SPADES, ACE, 400, 670);
    CardVisual FULLHOUE_HEARTSFIVE(HEARTS, FIVE, 475, 670);
    CardVisual FULLHOUSE_CLUBSFIVE(CLUBS, FIVE, 550, 670);


    //Creating text and card objects for flush
    sf::Text flush_text;
    flush_text.setFont(openSans);
    flush_text.setString("Flush:");
    flush_text.setPosition({50,900});
    flush_text.setCharacterSize(30);
    flush_text.setFillColor(sf::Color::Black);
    CardVisual FLUSH_4(CLUBS, FOUR, 250, 870);
    CardVisual FLUSH_jack(CLUBS, JACK, 325, 870);
    CardVisual FLUSH_7(CLUBS, SEVEN, 400,870);
    CardVisual FLUSH_2(CLUBS, TWO, 475, 870);
    CardVisual FLUSH_king(CLUBS, KING, 550, 870);



    //Creating text and card objects for straight
    sf::Text straight_text;
    straight_text.setFont(openSans);
    straight_text.setString("Straight:");
    straight_text.setPosition({1075,100});
    straight_text.setCharacterSize(30);
    straight_text.setFillColor(sf::Color::Black);
    CardVisual STRAIGHT_2(SPADES, TWO, 1300, 70);
    CardVisual STRAIGHT_3(CLUBS, THREE, 1375, 70);
    CardVisual STRAIGHT_4(SPADES, FOUR, 1450, 70);
    CardVisual STRAIGHT_5(HEARTS, FIVE, 1525, 70);
    CardVisual STRAIGHT_6(DIAMONDS, SIX, 1600, 70);



    //Creating text and card objects for 3 of a kind
    sf::Text threeKind_text;
    threeKind_text.setFont(openSans);
    threeKind_text.setString("Three of a Kind:");
    threeKind_text.setPosition({1075,300});
    threeKind_text.setCharacterSize(25);
    threeKind_text.setFillColor(sf::Color::Black);
    CardVisual THREEKIND_HEARTS(HEARTS, TWO, 1300, 270);
    CardVisual THREEKIND_odd1(CLUBS, NINE, 1375, 270);
    CardVisual THREEKIND_CLUBS(CLUBS, TWO, 1450, 270);
    CardVisual THREEKIND_odd2(HEARTS, SIX, 1525, 270);
    CardVisual THREEKIND_SPADES(SPADES, TWO, 1600, 270);


    //Creating text and card objects for two pair
    sf::Text twoPair_text;
    twoPair_text.setFont(openSans);
    twoPair_text.setString("Two Pair:");
    twoPair_text.setPosition({1075,500});
    twoPair_text.setCharacterSize(30);
    twoPair_text.setFillColor(sf::Color::Black);
    CardVisual TWO_PAIR_4c(CLUBS, FOUR, 1300, 470);
    CardVisual TWO_PAIR_odd(HEARTS, KING, 1375, 470);
    CardVisual TWO_PAIR_4d(DIAMONDS, FOUR, 1450, 470);
    CardVisual TWO_PAIR_10s(SPADES, TEN, 1525, 470);
    CardVisual TWO_PAIR_10h(HEARTS, TEN, 1600, 470);


    //Creating text and card objects for one pair
    sf::Text onePair_text;
    onePair_text.setFont(openSans);
    onePair_text.setString("One Pair:");
    onePair_text.setPosition({1075,700});
    onePair_text.setCharacterSize(30);
    onePair_text.setFillColor(sf::Color::Black);
    CardVisual ONE_PAIR_4c(CLUBS, FOUR, 1300, 670);
    CardVisual ONE_PAIR_odd(HEARTS, KING, 1375, 670);
    CardVisual ONE_PAIR_4d(DIAMONDS, FOUR, 1450, 670);
    CardVisual ONE_PAIR_odd2(SPADES, TEN, 1525, 670);
    CardVisual ONE_PAIR_odd3(HEARTS, EIGHT, 1600, 670);


    //Creating text and card objects for high card
    sf::Text highCard_text;
    highCard_text.setFont(openSans);
    highCard_text.setString("High Card:");
    highCard_text.setPosition({1075,900});
    highCard_text.setCharacterSize(30);
    highCard_text.setFillColor(sf::Color::Black);
    CardVisual HIGHCARD_1(DIAMONDS, FIVE, 1300, 870);
    CardVisual HIGHCARD_2(HEARTS, ACE, 1375, 870);
    CardVisual HIGHCARD_3(SPADES, QUEEN, 1450, 870);
    CardVisual HIGHCARD_4(CLUBS, SEVEN, 1525, 870);
    CardVisual HIGHCARD_5(HEARTS, TWO, 1600, 870);
    //////////////////////////////////////////
    //POKER ANALYSIS PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////







    //////////////////////////////////////////
//////////////////////////////////////////
    //DRAW CARD PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////
    CardVisual card(HEARTS, ACE, "big");
    //////////////////////////////////////////
//////////////////////////////////////////
    //DRAW CARD PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////



    //////////////////////////////////////////
//////////////////////////////////////////
    //BOUNCING BALL PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////
    sf::CircleShape bouncingBall;
    bouncingBall.setRadius(40.f);
    bouncingBall.setFillColor(sf::Color::Green);
    bouncingBall.setPosition({800, 200});
    float x = 0.3;
    float y = 0.3;
//////////////////////////////////////////
//////////////////////////////////////////
    //BOUNCING BALL PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////





    //////////////////////////////////////////
//////////////////////////////////////////
    //PONG PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////
    Ball ball(videoMode);
    Paddle leftPaddle;
    leftPaddle.setPaddlePos(0, videoMode.height/2);
    Paddle rightPaddle;
    rightPaddle.setPaddlePos(videoMode.width - rightPaddle.getGlobalBounds().width, videoMode.height/2);
//////////////////////////////////////////
//////////////////////////////////////////
    //PONG PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////





    /////////////////////////////////////////
//////////////////////////////////////////
    //TOP HAT GUY PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////
    TopHatGuy guy;
    guy.setPosition(videoMode.width/2, videoMode.height/2);
/////////////////////////////////////////
//////////////////////////////////////////
    //TOP HAT GUY PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////





    /////////////////////////////////////////
//////////////////////////////////////////
    //    MENU PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////

    sf::Font menuFont;
    menuFont.loadFromFile("Fonts/GroupeMedium-8MXgn.otf");
    sf::Text menuText;
    menuText.setFont(menuFont);
    menuText.setString("Main Menu");
    menuText.setCharacterSize(100);
    menuText.setPosition(videoMode.width/2 - 300, 50);



    sf::Text snakeMenuText;
    snakeMenuText.setFont(menuFont);
    snakeMenuText.setString("Snake");
    snakeMenuText.setCharacterSize(30);
    snakeMenuText.setPosition(100, 250);
    sf::Texture snakePreviewTexture;
    snakePreviewTexture.loadFromFile("Images/SnakeSS.png");
    sf::Sprite snakePreview;
    snakePreview.setTexture(snakePreviewTexture);
    snakePreview.setPosition(300, 400);
    snakePreview.setScale(0.5,0.5);




    sf::Text pokerMenuText;
    pokerMenuText.setFont(menuFont);
    pokerMenuText.setString("Poker Analysis");
    pokerMenuText.setCharacterSize(30);
    pokerMenuText.setPosition(250, 250);
    sf::Texture PApreviewTexture;
    PApreviewTexture.loadFromFile("Images/PokerAnalysis.png");
    sf::Sprite PAPreview;
    PAPreview.setTexture(PApreviewTexture);
    PAPreview.setPosition(300, 400);
    PAPreview.setScale(0.5,0.5);




    sf::Text pongMenuText;
    pongMenuText.setFont(menuFont);
    pongMenuText.setString("Pong");
    pongMenuText.setCharacterSize(30);
    pongMenuText.setPosition(580, 250);
    sf::Texture pongPreviewTexture;
    pongPreviewTexture.loadFromFile("Images/pongSS.png");
    sf::Sprite pongPreview;
    pongPreview.setTexture(pongPreviewTexture);
    pongPreview.setPosition(300, 400);
    pongPreview.setScale(0.5,0.5);


    sf::Text THGtext;
    THGtext.setFont(menuFont);
    THGtext.setString("Top Hat Guy");
    THGtext.setCharacterSize(30);
    THGtext.setPosition(720, 250);
    sf::Texture THGpreviewTexture;
    THGpreviewTexture.loadFromFile("Images/THG_SS.png");
    sf::Sprite THG_preview;
    THG_preview.setTexture(THGpreviewTexture);
    THG_preview.setPosition(300, 400);
    THG_preview.setScale(0.5,0.5);

    sf::Text drawCardText;
    drawCardText.setFont(menuFont);
    drawCardText.setString("Draw Card");
    drawCardText.setCharacterSize(30);
    drawCardText.setPosition(1000, 250);
    sf::Texture DCpreviewTexture;
    DCpreviewTexture.loadFromFile("Images/DC_SS.png");
    sf::Sprite DCpreview;
    DCpreview.setTexture(DCpreviewTexture);
    DCpreview.setPosition(300, 400);
    DCpreview.setScale(0.5,0.5);


    sf::Text greenCircleText;
    greenCircleText.setFont(menuFont);
    greenCircleText.setString("Green Circle");
    greenCircleText.setCharacterSize(30);
    greenCircleText.setPosition(1250, 250);
    sf::Texture GCpreviewTexture;
    GCpreviewTexture.loadFromFile("Images/greenCircSS.png");
    sf::Sprite GCpreview;
    GCpreview.setTexture(GCpreviewTexture);
    GCpreview.setPosition(300, 400);
    GCpreview.setScale(0.5,0.5);



    sf::Text bouncinBallText;
    bouncinBallText.setFont(menuFont);
    bouncinBallText.setString("Bouncing Ball");
    bouncinBallText.setCharacterSize(30);
    bouncinBallText.setPosition(1550, 250);
    sf::Texture BBpreviewTexture;
    BBpreviewTexture.loadFromFile("Images/bouncingBallSS.png");
    sf::Sprite BBpreview;
    BBpreview.setTexture(BBpreviewTexture);
    BBpreview.setPosition(300, 400);
    BBpreview.setScale(0.5,0.5);

    sf::Text backToMainMenu;
    backToMainMenu.setFont(menuFont);
    backToMainMenu.setString("Back to Main Menu");
    backToMainMenu.setCharacterSize(80);
    backToMainMenu.setPosition(videoMode.width/2 - 450, videoMode.height- 200);


/////////////////////////////////////////
//////////////////////////////////////////
    //    MENU PRE WINDOW OBJECT DECLARATIONS
    ///////////////////////////////////////




    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }

        if (windowStates.isMenuShowing()== true){

            window.clear();




            sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);

            if (snakeMenuText.getGlobalBounds().contains(m_pos)) {
                snakeMenuText.setFillColor(sf::Color::Cyan);
                window.draw(snakePreview);

            } else {
                snakeMenuText.setFillColor(sf::Color::White);
            }
            if (snakeMenuText.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(2);
            }


            if (pokerMenuText.getGlobalBounds().contains(m_pos)) {
                pokerMenuText.setFillColor(sf::Color::Cyan);
                window.draw(PAPreview);
            } else {
                pokerMenuText.setFillColor(sf::Color::White);
            }
            if (pokerMenuText.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(3);
            }


            if (pongMenuText.getGlobalBounds().contains(m_pos)) {
                pongMenuText.setFillColor(sf::Color::Cyan);
                window.draw(pongPreview);
            } else {
                pongMenuText.setFillColor(sf::Color::White);
            }
            if (pongMenuText.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(4);
            }


            if (THGtext.getGlobalBounds().contains(m_pos)) {
                THGtext.setFillColor(sf::Color::Cyan);
                window.draw(THG_preview);
            } else {
                THGtext.setFillColor(sf::Color::White);
            }
            if (THGtext.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(5);
            }


            if (drawCardText.getGlobalBounds().contains(m_pos)) {
                drawCardText.setFillColor(sf::Color::Cyan);
                window.draw(DCpreview);
            } else {
                drawCardText.setFillColor(sf::Color::White);
            }
            if (drawCardText.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(6);
            }

            if (greenCircleText.getGlobalBounds().contains(m_pos)) {
                greenCircleText.setFillColor(sf::Color::Cyan);
                window.draw(GCpreview);
            } else {
                greenCircleText.setFillColor(sf::Color::White);
            }
            if (greenCircleText.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(7);
            }

            if (bouncinBallText.getGlobalBounds().contains(m_pos)) {
                bouncinBallText.setFillColor(sf::Color::Cyan);
                window.draw(BBpreview);
            } else {
                bouncinBallText.setFillColor(sf::Color::White);
            }
            if (bouncinBallText.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(8);
            }






            window.draw(menuText);
            window.draw(snakeMenuText);
            window.draw(pokerMenuText);
            window.draw(pongMenuText);
            window.draw(THGtext);
            window.draw(drawCardText);
            window.draw(greenCircleText);
            window.draw(bouncinBallText);



            window.display();
        }








        if(windowStates.isSnakeShowing() == true) {
            window.setFramerateLimit(25);

            backToMainMenu.setPosition(videoMode.width/2 - 450, videoMode.height- 200);
            backToMainMenu.setScale(1,1);


            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

            }

            if (snake.isDead()) {
                sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);

                if (restart.getGlobalBounds().contains(m_pos)) {
                    restart.setFillColor(sf::Color::Red);
                } else {
                    restart.setFillColor(sf::Color::Yellow);
                }
                if (restart.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    snake.restart(videoMode);
                    snake.toggleDirection('1');
                }


                if (backToMainMenu.getGlobalBounds().contains(m_pos)) {
                    backToMainMenu.setFillColor(sf::Color::Red);
                } else {
                    backToMainMenu.setFillColor(sf::Color::Yellow);
                }
                if (backToMainMenu.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    snake.restart(videoMode);
                    snake.toggleDirection('1');
                    windowStates.toggleState(1);

                }



            }


            if (!snake.isDead()) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                    if (!snake.isGoingRight()) {
                        snake.toggleDirection('L');
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                    if (!snake.isGoingDown()) {
                        snake.toggleDirection('U');
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                    if (!snake.isGoingLeft()) {
                        snake.toggleDirection('R');
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                    if (!snake.isGoingUp()) {
                        snake.toggleDirection('D');
                    }
                }
            }


            window.clear();
            window.draw(bioBackground);


            if (!snake.OutOfBounds(videoMode) && !snake.isSelfCollide()) {
                snake.move();
            } else {
                snake.toggleDirection('0');
            }


            window.draw(snake);

            if (snake.getLeadCellGB().intersects(food.getGlobalBounds())) {
                sf::Vector2i pos = food.generatePos(videoMode);
                food.relocate(pos);
                bool found = false;
                while (!found) {
                    found = true;
                    for (int i = 0; i < snake.getLength(); i++) {
                        if (snake[i].getGlobalBounds().intersects(food.getGlobalBounds())) {
                            found = false;
                            pos = food.generatePos(videoMode);
                            food.relocate(pos);
                        }
                    }
                }
                snake.grow();
            } else {
                window.draw(food);
            }


            scoreNum = std::to_string(snake.getLength() - 1);
            score.setString("SCORE: " + scoreNum);
            window.draw(score);
            window.draw(topBorder);
            if (snake.isDead()) {
                window.draw(restart);
                window.draw(backToMainMenu);
            }

            window.display();

        }




        if(windowStates.isPongShowing() == true){
            window.setFramerateLimit(10000);

            sf::FloatRect leftDime = leftPaddle.getGlobalBounds();
            sf::FloatRect rightDime = rightPaddle.getGlobalBounds();
            ball.bounce(leftDime, rightDime, videoMode);
            backToMainMenu.setScale(0.5,0.5);
            backToMainMenu.setPosition(100,100);



            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                leftPaddle.movePaddleUp(videoMode);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                leftPaddle.movePaddleDown(videoMode);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                rightPaddle.movePaddleUp(videoMode);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                rightPaddle.movePaddleDown(videoMode);
            }


            window.clear(sf::Color::Black);
            window.draw(ball);
            window.draw(leftPaddle);
            window.draw(rightPaddle);

            if (ball.isOutOfBounds(videoMode)) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    ball.reset(videoMode);
                }
                sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);


                if (backToMainMenu.getGlobalBounds().contains(m_pos)) {
                    backToMainMenu.setFillColor(sf::Color::Blue);
                } else {
                    backToMainMenu.setFillColor(sf::Color::Cyan);
                }
                if (backToMainMenu.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    ball.reset(videoMode);
                    windowStates.toggleState(1);
                }

                window.draw(backToMainMenu);

            }
            window.display();
        }


        if (windowStates.isBouncingBallShowing() == true){
            window.setFramerateLimit(100000);
            bouncingBall.setRadius(40.f);


            sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);


            if (backToMainMenu.getGlobalBounds().contains(m_pos)) {
                backToMainMenu.setFillColor(sf::Color::Blue);
            } else {
                backToMainMenu.setFillColor(sf::Color::Cyan);
            }
            if (backToMainMenu.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(1);
            }

            backToMainMenu.setScale(0.5,0.5);
            backToMainMenu.setPosition(100,100);

            window.clear();

            bounce(bouncingBall, x, y, videoMode);
            window.draw(bouncingBall);
            window.draw(backToMainMenu);

            window.display();

        }


        if (windowStates.isThgShowing() == true){
            window.setFramerateLimit(100000);

            sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);


            if (backToMainMenu.getGlobalBounds().contains(m_pos)) {
                backToMainMenu.setFillColor(sf::Color::Black);
            } else {
                backToMainMenu.setFillColor(sf::Color::Red);
            }
            if (backToMainMenu.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(1);
            }

            backToMainMenu.setScale(0.5,0.5);
            backToMainMenu.setPosition(100,100);

            window.clear(sf::Color::Yellow);

            window.draw(guy);
            window.draw(backToMainMenu);

            window.display();
        }


        if (windowStates.isGcShowing()== true){
            window.setFramerateLimit(100000);
            bouncingBall.setRadius(100);
            bouncingBall.setPosition({800, 200});


            sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);


            if (backToMainMenu.getGlobalBounds().contains(m_pos)) {
                backToMainMenu.setFillColor(sf::Color::Blue);
            } else {
                backToMainMenu.setFillColor(sf::Color::Cyan);
            }
            if (backToMainMenu.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(1);
            }

            backToMainMenu.setScale(0.5,0.5);
            backToMainMenu.setPosition(100,100);

            window.clear();

            window.draw(bouncingBall);
            window.draw(backToMainMenu);

            window.display();
        }


        if (windowStates.isDrawCardShowing() == true){
            sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);


            if (backToMainMenu.getGlobalBounds().contains(m_pos)) {
                backToMainMenu.setFillColor(sf::Color::Blue);
            } else {
                backToMainMenu.setFillColor(sf::Color::Cyan);
            }
            if (backToMainMenu.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(1);
            }

            backToMainMenu.setScale(0.5,0.5);
            backToMainMenu.setPosition(100,100);


            card.setPosition(400,videoMode.height/2);

            window.clear();
            window.draw(card);
            window.draw(backToMainMenu);
            window.display();

        }


        if (windowStates.isPokerShowing() == true){
            window.clear(sf::Color::Green);
            window.draw(royalFlush_text);
            window.draw(ROYALFLUSH_ace);    //drawing royal flush
            window.draw(ROYALFLUSH_king);
            window.draw(ROYALFLUSH_queen);
            window.draw(ROYALFLUSH_jack);
            window.draw(ROYALFLUSH_ten);
            prob.setPosition(650,100);
            window.draw(prob);
            s = std::to_string((pScore.getRoyalFLushCount()/trialNum)*100);
            num.setString(s+"%");
            num.setPosition(850, 100);
            window.draw(num);




            window.draw(straightFlush_text);
            window.draw(STRAIGHTFLUSH_2);
            window.draw(STRAIGHTFLUSH_3);
            window.draw(STRAIGHTFLUSH_4);   //drawing straight flush
            window.draw(STRAIGHTFLUSH_5);
            window.draw(STRAIGHTFLUSH_6);
            prob.setPosition(650,300);
            window.draw(prob);
            s = std::to_string((pScore.getStraightFlushCount()/trialNum)*100);
            num.setString(s+"%");
            num.setPosition(850, 300);
            window.draw(num);


            window.draw(fourKind_text);
            prob.setPosition(650,500);
            window.draw(prob);
            window.draw(FOURKIND_CLUBS);
            window.draw(FOURKIND_HEARTS); //drawing 4 of a kind
            window.draw(FOURKIND_DIAMONDS);
            window.draw(FOURKIND_SPADES);
            window.draw(FOURKIND_ODD);
            s = std::to_string((pScore.getFourKindcount()/trialNum)*100);
            num.setString(s+"%");
            num.setPosition(850, 500);
            window.draw(num);


            window.draw(fullHouse_text);
            prob.setPosition(650,700);
            window.draw(prob);
            window.draw(FULLHOUSE_DIAMONDSACE);
            window.draw(FULLHOUE_HEARTSFIVE);
            window.draw(FULLHOUSE_SPADESACE);   //drawing full house
            window.draw(FULLHOUSE_SPADESFIVE);
            window.draw(FULLHOUSE_CLUBSFIVE);
            s = std::to_string((pScore.getFHcount()/trialNum)*100);
            num.setString(s+"%");
            num.setPosition(850, 700);
            window.draw(num);


            window.draw(flush_text);
            prob.setPosition(650,900);
            window.draw(prob);
            window.draw(FLUSH_2);
            window.draw(FLUSH_4);   //drawing flush
            window.draw(FLUSH_jack);
            window.draw(FLUSH_7);
            window.draw(FLUSH_king);
            s = std::to_string((pScore.getFlushCount()/trialNum)*100);
            num.setString(s+"%");
            num.setPosition(850, 900);
            window.draw(num);



            window.draw(straight_text);
            prob.setPosition(1675,100);
            window.draw(prob);
            window.draw(STRAIGHT_2);
            window.draw(STRAIGHT_3);
            window.draw(STRAIGHT_4);    //drawing straight
            window.draw(STRAIGHT_5);
            window.draw(STRAIGHT_6);
            s = std::to_string((pScore.getStraightCount()/trialNum)*100);
            num.setString(s+"%");
            num.setPosition(1850, 100);
            window.draw(num);



            window.draw(threeKind_text);
            prob.setPosition(1675,300);
            window.draw(prob);
            window.draw(THREEKIND_HEARTS);
            window.draw(THREEKIND_odd1);    //drawing three of a kind
            window.draw(THREEKIND_CLUBS);
            window.draw(THREEKIND_odd2);
            window.draw(THREEKIND_SPADES);
            s = std::to_string((pScore.getThreeKind()/trialNum)*100);
            num.setString(s+"%");
            num.setPosition(1850, 300);
            window.draw(num);



            window.draw(twoPair_text);
            prob.setPosition(1675,500);
            window.draw(prob);
            window.draw(TWO_PAIR_4c);
            window.draw(TWO_PAIR_4d);
            window.draw(TWO_PAIR_odd);
            window.draw(TWO_PAIR_10h);  //drawing two pair
            window.draw(TWO_PAIR_10s);
            s = std::to_string((pScore.getTwoPairCount()/trialNum)*100);
            num.setString(s+"%");
            num.setPosition(1850, 500);
            window.draw(num);





            window.draw(onePair_text);
            prob.setPosition(1675,700);
            window.draw(prob);
            window.draw(ONE_PAIR_odd2);
            window.draw(ONE_PAIR_odd3);
            window.draw(ONE_PAIR_4c);   //drawing one pair
            window.draw(ONE_PAIR_odd);
            window.draw(ONE_PAIR_4d);
            s = std::to_string((pScore.getOnePairCount()/trialNum)*100);
            num.setString(s+"%");
            num.setPosition(1850, 700);
            window.draw(num);



            window.draw(highCard_text);
            prob.setPosition(1675,900);
            window.draw(prob);
            window.draw(HIGHCARD_1);
            window.draw(HIGHCARD_2);
            window.draw(HIGHCARD_3);    //drawing high card
            window.draw(HIGHCARD_4);
            window.draw(HIGHCARD_5);
            num.setString("100%");
            num.setPosition(1850, 900);
            window.draw(num);



            sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);


            if (backToMainMenu.getGlobalBounds().contains(m_pos)) {
                backToMainMenu.setFillColor(sf::Color::Red);
            } else {
                backToMainMenu.setFillColor(sf::Color::Black);
            }
            if (backToMainMenu.getGlobalBounds().contains(m_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                windowStates.toggleState(1);
            }


            backToMainMenu.setPosition(videoMode.width/2 - 250, videoMode.height- 200);
            backToMainMenu.setScale(0.5,0.5);
            window.draw(backToMainMenu);



            window.display();
        }


    }
    return 0;
}
