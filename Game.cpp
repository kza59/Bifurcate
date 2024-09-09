#include "include/Game.h"
#include <iostream>
#include <ctime>
#include "config.h"

// #include "Global.h"

void Game::initWindow()
{
    this->videoMode.height = 700;
    this->videoMode.width = 700;
    // this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Fullscreen);
    this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Default);

    this->window->setFramerateLimit(144);
    this->window->setPosition(sf::Vector2i(500, 0));
}

void Game::initVars()
{

    this->window = nullptr;
    // game logic
    this->points = 0;
    this->enemySpawnTimerMax = 100.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 1;
    if (!this->font.loadFromFile("Fonts/times.ttf"))
    {
    }
    else
    {
        this->font.loadFromFile("Fonts/times.ttf");
    }
    this->mouseCursor.setRadius(5.f);
    this->mouseCursor.setOutlineColor(sf::Color::White);
    this->mouseCursor.setFillColor(sf::Color::White);
    this->mouseCursor.setScale(sf::Vector2f(2.f, 2.f));
    this->mouseCursor.setOutlineThickness(1.f);
    this->mouseCursor.setPosition(20.f, 20.f);
    this->cursorPos.setFont(this->font);
    this->cursorPos.setPosition(sf::Vector2f(0.f, 0.f));
    this->cursorPos.setFillColor(sf::Color::Green);
    this->cursorPos.setCharacterSize(30);
    this->playerPos.setFont(this->font);
    this->playerPos.setPosition(sf::Vector2f(800.f, 0.f));
    this->playerPos.setFillColor(sf::Color::Cyan);
    this->playerPos.setCharacterSize(30);
    this->stats.setFont(this->font);
    this->stats.setPosition(sf::Vector2f(300.f, 0.f));
    this->stats.setFillColor(sf::Color::Red);
    this->stats.setCharacterSize(30);
    this->currentScore = 0;
    this->Timer = 0.f;
    this->playerHP.setFont(this->font);
    this->playerHP.setPosition(sf::Vector2f(1000.f, 0.f));
    this->playerHP.setFillColor(sf::Color::Red);
    this->playerHP.setCharacterSize(30);
    this->playerHP.setString(to_string(100));
    // this->cursorPos.setString("Test");
}

void Game::initEnemy()
{
    this->enemy.bod.setPosition(20.f, 20.f);
    this->enemy.bod.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.bod.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.bod.setFillColor(sf::Color::Cyan);
    this->enemy.bod.setOutlineColor(sf::Color::White);
    this->enemy.bod.setOutlineThickness(1.f);
    this->enemy.acceleration = sf::Vector2f(-9.81f, 0.f);
}

void Game::initPlayer()
{
    this->player.bod.setPosition(10.f, 100.f);
    this->player.bod.setSize(sf::Vector2f(100.f, 100.f));
    this->player.bod.setScale(sf::Vector2f(0.5f, 0.5f));
    this->player.bod.setFillColor(sf::Color::Cyan);
    this->player.bod.setOutlineColor(sf::Color::White);
    this->player.bod.setOutlineThickness(1.f);
    this->player.acceleration = sf::Vector2f(0.f, 9.81f);
}

void Game::openMenu() {
    while(true) {
        // this->window->draw(this->Menu);
        // if(sf::Event::KeyPressed) {
        // }
    }
}

Game::Game()
{
    this->initVars();
    this->initWindow();
    this->initEnemy();
    this->initPlayer();
}

Game::~Game()
{
    delete this->window;
}

const bool Game::running() const
{
    return this->window->isOpen();
}
// functions
float jumpTimer = 0.0f;

void Game::pollEvents()
{

    // jumpCD = 10.0f;
    jumpCD = 0.f;

    bool isJumping = false;
    /*
    @return void
    Polls the events
    1. while the window is polling events, process events
    Functionalities:
    {
    Close/Escape : closes the window
    W/A/S/D : moves the character around accordingly

    }
    */
    bool W, A, S, D, Spc;

    while (this->window->pollEvent(this->e))

    {
        jumpTimer += 1.f;

        // taking in events
        switch (this->e.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:

            switch (e.key.code)
            {
            case sf::Keyboard::Escape:
                this->window->close();
            case sf::Keyboard::E:
                this->createDefaultProjectile(this->player.bod.getPosition());
                break;
            // case sf::Keyboard::
            default:
                break;
            }
            break;
        case sf::Event::Resized:
            break;
        case sf::Event::LostFocus:
            break;
        case sf::Event::GainedFocus:
            break;
        case sf::Event::TextEntered:
            break;
        case sf::Event::KeyReleased:
            break;
        case sf::Event::MouseWheelMoved:
            break;
        case sf::Event::MouseWheelScrolled:
            break;
        case sf::Event::MouseButtonPressed:
            break;
        case sf::Event::MouseButtonReleased:
            break;
        case sf::Event::MouseMoved:
            break;
        case sf::Event::MouseLeft:
            break;
        case sf::Event::MouseEntered:
            break;
        case sf::Event::JoystickButtonPressed:
            break;
        case sf::Event::JoystickButtonReleased:
            break;
        case sf::Event::JoystickMoved:
            break;
        case sf::Event::JoystickConnected:
            break;
        case sf::Event::JoystickDisconnected:
            break;
        case sf::Event::TouchBegan:
            break;
        case sf::Event::TouchMoved:
            break;
        case sf::Event::TouchEnded:
            break;
        case sf::Event::SensorChanged:
            break;
        case sf::Event::Count:
            break;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
    {
        this->window->close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(onLadder()) {
        this->player.bod.move(sf::Vector2f(0.f, -5.f));
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->player.bod.move(sf::Vector2f(-5.f, 0.f));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->player.bod.move(sf::Vector2f(0.f, 5.f));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->player.bod.move(sf::Vector2f(5.f, 0.f));
    }
    if (!inAir() && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->player.velocity.y = -20.f;
        // this->player.bod.move(sf::Vector2f(5.f, 0.f));

    }
    else if (!inAir() && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->player.velocity.y = -20.f;
        // this->player.bod.move(sf::Vector2f(-5.f, 0.f));

    }
    else if (!inAir() && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->player.velocity.y = -20.f;

    }

}

bool Game::inAir()
{
    return this->player.velocity.y != 0;
}

bool Game::onLadder() {
    return false;
}

void Game::createDefaultProjectile(sf::Vector2f pos) {
    //Purpose: creates a projectile originating at the given location.
    this->projectile.projectileSprite.setFillColor(sf::Color::Magenta);
    this->projectile.projectileSprite.setPosition(pos);
    this->projectile.velocity = sf::Vector2f(1.f,1.f);
    this->projectile.acceleration = sf::Vector2f(0.f,0.f);
    this->projectile.position = pos;
    this->projectile.projectileSprite.setRadius(5.f);
    this->projectile.projectileDamage = 3.5;
    this->projectile.lifeTime = 0.f;
    this->projectile.projClock.restart();
    this->projectiles.push_back(this->projectile);
}

void Game::updateProjectiles() {
for(auto it = this->projectiles.begin(); it != this->projectiles.end();) {
    auto &item = *it;                               
    item.lifeTime += (item.projClock.getElapsedTime()).asSeconds();
    // cout << item.lifeTime << endl;
    item.projClock.restart();

    if(item.lifeTime > 5.f) { //projectile erasure
            it = this->projectiles.erase(it);
    }

    else {

    
        if (item.position.y < this->window->getSize().y)
        {
                    item.projectileSprite.move(item.velocity.x, item.velocity.y);

        }

        sf::Vector2f position = item.projectileSprite.getPosition();
        sf::Vector2f size = sf::Vector2f(this->projectile.projectileSprite.getRadius(),this->projectile.projectileSprite.getRadius());

        // collision detection with window boundaries
        if (position.x + size.x / 2 >= this->window->getSize().x)
        {
            item.velocity.x = -abs(item.velocity.x);
        }
        if (position.x <= 0)
        {
            item.velocity.x = abs(item.velocity.x);
        }
        if (position.y + size.y / 2 >= this->window->getSize().y)
        {
            item.velocity.y = -abs(item.velocity.y);
            // item.velocity.y = 0;
        }
        if (position.y <= 0)
        {
            item.velocity.y = abs(item.velocity.y);
        }
        
 bool hitEnemy = false;
        for (auto it2 = this->enemies.begin(); it2 != this->enemies.end();) {
            auto &enemy = *it2;
            if (checkCollision2(item.projectileSprite.getPosition(), enemy.bod.getPosition(), item.projectileSprite.getRadius(), enemy.bod.getSize().x)) {
                std::cout << "\nhit\n" << std::endl;
                std::cout << item.lifeTime << std::endl;
                hitEnemy = true;
                it2 = this->enemies.erase(it2); 
                break; 
            } else {
                ++it2;
            }
        }

        if (hitEnemy) {
            it = this->projectiles.erase(it);
            this->currentScore++;

        } else {
            ++it;
        }
}
}
}

void Game::renderProjectiles() {
    for(auto& item : this->projectiles) {
        this->window->draw(item.projectileSprite);
    }
}

void Game::createEnemy()
{
    /*
    Creates enemies, setting their traits.
    1. sets the positions of the enemy to some random x and y
    2. sets the color of the enemy to red
    3. pushes the enemy into the vector
    */
    this->enemy.bod.setPosition(
        static_cast<float>(rand() % this->window->getSize().x - this->enemy.bod.getSize().x),
        static_cast<float>(rand() % this->window->getSize().y - this->enemy.bod.getSize().y));
    srand(time(0));
    float initVelocityX = 3.f;
    float initVelocityY = 3.f;
    initVelocityX = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 10.f);
    initVelocityY = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 10.f);

    this->enemy.velocity = sf::Vector2f(initVelocityX, initVelocityY);
    this->enemy.acceleration = sf::Vector2f(0.f, 9.81f);
    // this->body.acceleration = sf::Vector2f(0.f, 9.81f);

    this->enemy.bod.setFillColor(sf::Color::Blue);
    this->enemies.push_back(this->enemy);

    this->body.position = sf::Vector2f(static_cast<float>(rand() % this->window->getSize().x - this->enemy.bod.getSize().x),
                                       static_cast<float>(rand() % this->window->getSize().y - this->enemy.bod.getSize().y));
    this->bodies.push_back(this->body);
}

void Game::mainMenu() {
    //Purpose: return to the main menu
}

void Game::updateEnemies()
{
    /*
    Updates the enemies vector
    Checks for collisions and then resolves them.
    */
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            this->createEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
    }

    bool mouseClicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    for (auto it = this->enemies.begin(); it != this->enemies.end(); /* no increment here */)
    {

        auto &item = *it;
        // item.update(0.01f);
        // item.velocity = sf::Vector2f(0.f,0.f);
        // item.update(0.1f);
        if (item.position.y > this->window->getSize().y)
        {
        }
        else
        {
            item.bod.move(item.velocity.x, item.velocity.y);
            item.update(0.05f);
            // item.bod.setPosition(sf::Vector2f(item.position.x, item.position.y));
        }

        sf::Vector2f position = item.bod.getPosition();
        sf::Vector2f size = item.bod.getSize();

        // collision detection with window boundaries
        if (position.x + size.x / 2 >= this->window->getSize().x)
        {
            item.velocity.x = -abs(item.velocity.x);
        }
        if (position.x <= 0)
        {
            item.velocity.x = abs(item.velocity.x);
        }
        if (position.y + size.y / 2 >= this->window->getSize().y)
        {
            item.velocity.y = -abs(item.velocity.y);
            // item.velocity.y = 0;
        }
        if (position.y <= 0)
        {
            item.velocity.y = abs(item.velocity.y);
        }


        if ( // killing mechanism
            mouseClicked && this->mouseRelToWindow.x >= position.x && this->mouseRelToWindow.x <= position.x + size.x / 2 &&
            this->mouseRelToWindow.y >= position.y && this->mouseRelToWindow.y <= position.y + size.y / 2)
        {
            it = this->enemies.erase(it);
            this->currentScore += 1;
        }
        else
        {
            ++it;
        }


        // if(item.bod.getPosition() == this->player.bod.getPosition())  {
        //     //player hurting mechanism
        //     this->window->close();
        // }
        
        if(checkCollision2(this->player.bod.getPosition(), item.bod.getPosition(), this->player.bod.getSize().x/2, item.bod.getSize().x/2)) {
                        // this->window->close();
                        // cout << "DEAD" << endl;

        }
    }
}

void Game::renderEnemies()
{
    /*
    Renders all the enemies in the enemies vector
    */
    for (auto &item : this->enemies)
    {
        this->window->draw(item.bod);
    }
}

void Game::updateMousePos()
{
    /*
    Updates the mouse position relative to the window
    1. While the game is running, will constantly keep track of the position of the mouse relative to the window
    */
    this->mouseRelToWindow = sf::Mouse::getPosition(*this->window);
    this->mouseCursor.setPosition(static_cast<float>(this->mouseRelToWindow.x) - this->mouseCursor.getRadius(),
                                  static_cast<float>(this->mouseRelToWindow.y) - this->mouseCursor.getRadius());
    this->cursorPos.setString("X:   " + to_string(static_cast<float>(this->mouseRelToWindow.x) - this->mouseCursor.getRadius()) + "\nY:   " + to_string(static_cast<float>(this->mouseRelToWindow.y) - this->mouseCursor.getRadius()));
}

void Game::renderMousePos()
{
    /*
    Renders the mouse position
    */
    this->window->draw(this->mouseCursor);
    //    this->window->draw(this->cursorPos);

    //    this->window->draw(this->mouseRelToWindow);
}

void Game::updateStats()
{
    /*
    Updates the mouse position relative to the window
    1. While the game is running, will constantly keep track of the position of the mouse relative to the window
    */
    this->mouseRelToWindow = sf::Mouse::getPosition(*this->window);
    this->mouseCursor.setPosition(static_cast<float>(this->mouseRelToWindow.x) - this->mouseCursor.getRadius(),
                                  static_cast<float>(this->mouseRelToWindow.y) - this->mouseCursor.getRadius());
    this->cursorPos.setString("X:   " + to_string(static_cast<float>(this->mouseRelToWindow.x) - this->mouseCursor.getRadius()) + "\nY:   " + to_string(static_cast<float>(this->mouseRelToWindow.y) - this->mouseCursor.getRadius()));
    this->Timer += (this->Clock.getElapsedTime()).asSeconds();
    // cout << this->Timer << endl;
    this->Clock.restart();
    this->stats.setString("Score:   " + to_string(this->currentScore) + "   Time:   " + to_string(this->Timer));
}

void Game::renderStats()
{
    this->window->draw(this->cursorPos);
    this->window->draw(this->stats);
    this->window->draw(this->playerPos);

}

void Game::updatePlayer()
{ // if the arrow keys are pressed then we update the player?
    this->playerPos.setString("X:   " + to_string(static_cast<float>(this->player.bod.getPosition().x) - this->player.bod.getSize().x/2) + "\nY:   " + to_string(static_cast<float>(this->player.bod.getPosition().y) - this->player.bod.getSize().y/2));

    if (player.bod.getPosition().y + player.bod.getSize().y / 2 > this->window->getSize().y)
    {
        // player.position.y = 100.f;
        player.bod.move(0.f, -4.91f);
        // player.velocity = sf::Vector2f(0.f,0.f);
        player.acceleration.y = 0; // downwards acceleration should be locked here
    }
    else
    {
        this->player.bod.move(this->player.velocity.x, this->player.velocity.y);
        // player.acceleration.y = 9.81;
        this->player.update(0.1f);
    }

    if (player.bod.getPosition().y + player.bod.getSize().y / 2 + 100.f < this->window->getSize().y)
    {
        player.acceleration.y = 9.81;
    }

    sf::Vector2f position = this->player.bod.getPosition();
    sf::Vector2f size = this->player.bod.getSize();
    auto &item = this->player;
    if (position.x + size.x / 2 >= this->window->getSize().x)
    {
        item.velocity.x = -abs(item.velocity.x);
    }
    if (position.x <= 0)
    {
        item.velocity.x = abs(item.velocity.x);
    }
    if (position.y + size.y / 2 >= this->window->getSize().y)
    {
        // item.velocity.y = -abs(item.velocity.y);
        // item.velocity.y = 0;
        item.velocity.y = 0;
    }
    if (position.y <= 0)
    {
        // item.velocity.y = abs(item.velocity.y);
        item.velocity.y = 0;
    }
}

void Game::renderPlayer()
{
    this->window->draw(this->player.bod);
}

void Game::update()
{
    /*
    @return void
    Updates the game
    1. calls pollEvents
    2. updates mouse position
    */
    this->pollEvents();
    this->updatePlayer();
    this->updateEnemies();
    this->updateStats();
    this->updateProjectiles();
}

void Game::render()
{
    /*
    @return void
    Renders the game
    1. clears the window
    1.5. draws the game objects
    2. displays the window
    */
    this->window->clear();
    this->renderEnemies();
    this->renderPlayer();
    this->renderMousePos();
    // this->renderPlayerPos();
    this->renderStats();
    this->renderProjectiles();
    this->window->display();
}
