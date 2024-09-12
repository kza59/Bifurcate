#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "Physics.h"
#include "GUI.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

using namespace std;


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
    bool inMenu;
    float Timer;

    // game objects
    Body enemy;
    // vector<sf::RectangleShape> enemies;
    vector<Body> enemies;
    int playerOrient; //0:left 1:right
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
    sf::CircleShape mouseCursor;
    sf::Text cursorPos;
    sf::Text playerPos;
    sf::Text playerHP;
    sf::Text stats;
    sf::Clock Clock;
    Button testButton;
    Menu menu;
    OptionsMenu optionsMenu;
    // sf::Text currentScore;
    int currentScore;

public:
    // constructor and destructor
    Game();
    void openOptions();
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
    void openOptionsMenu();
    void mainMenu();
    void createButton(string &Text, float length, float height, sf::Color color);
    void updateButton();
    void renderButton();
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
