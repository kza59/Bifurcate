#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "Physics.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

using namespace std;
class Button
{
public:
    Button() {

    }
    Button(float x, float y, float width, float height, const sf::Font &font, const std::string &text)
    {
        button.setSize(sf::Vector2f(width, height));
        button.setPosition(x, y);
        button.setFillColor(sf::Color::Blue);

        buttonText.setFont(font);
        buttonText.setString(text);
        buttonText.setCharacterSize(24);
        buttonText.setFillColor(sf::Color::Blue);
        buttonText.setPosition(
            x + (width - buttonText.getLocalBounds().width)/2,
            y + (height - buttonText.getLocalBounds().height)/2);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(button);
        window.draw(buttonText);
    }

    bool isClicked(const sf::Vector2i &mousePos)
    {
        return button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

private:
    sf::RectangleShape button;
    sf::Text buttonText;
};

class Game
{
private:
    // private variables
    sf::Vector2i mouseRelToWindow;

    // game logic
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    long unsigned int maxEnemies;
    int points;
    float jumpCD;
    float jumpTimer;
    bool isJumping;

    float Timer;

    // game objects
    Body enemy;
    // vector<sf::RectangleShape> enemies;
    vector<Body> enemies;
    Body player;
    sf::Vector2f velocity;
    Body body;
    vector<Body> bodies;
    Projectile projectile;
    vector<Projectile> projectiles;

    // private functions
    void initVars();
    void initWindow();
    void initEnemy();
    void initPlayer();
    sf::RenderWindow *window;
    sf::Event e;
    // sf::;
    sf::VideoMode videoMode;
    sf::Font font;
    Button fullScreenButton;
    sf::CircleShape mouseCursor;
    sf::Text cursorPos;
    sf::Text playerPos;
    sf::Text playerHP;
    sf::Text stats;
    sf::Clock Clock;
    // sf::Text currentScore;
    int currentScore;

public:
    // constructor and destructor
    Game();
    virtual ~Game();
    // checkers
    const bool running() const;
    void renderMousePos();
    void updateStats();
    void renderStats();
    void updatePlayer();
    void renderPlayer();
    // functions
    void update();
    void render();
    void updateMousePos();
    void pollEvents();
    void openMenu();
    void mainMenu();
    void createDefaultProjectile(sf::Vector2f pos);
    void updateProjectiles();
    void renderProjectiles();
    bool inAir();
    bool onLadder();
    void createEnemy();
    void updateEnemies();
    void renderEnemies();
};

#endif
