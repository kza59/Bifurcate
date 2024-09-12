#ifndef GUI_H
#define GUI_H
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
        buttonText.setFillColor(sf::Color::White);
        buttonText.setPosition(
            x + (width - buttonText.getLocalBounds().width)/2,
            y + (height - buttonText.getLocalBounds().height)/2);
    }
    void setButtonText(string Text) {
        buttonText.setString(Text);
    }
    void draw(sf::RenderWindow &window)
    {
        window.draw(button);
        window.draw(buttonText);
    }
    void setBackGroundColor(sf::Color color) {
        button.setFillColor(color);
    }
    void setTextSize(/*sf::Vector2f vect*/ float size) {
        // buttonText.setScale(vect);
        buttonText.setCharacterSize(size);
    }
    void highlightButton() {

        this->button.setFillColor(sf::Color::Cyan);
    }
    void resetButton() {

        this->button.setFillColor(sf::Color::Blue);
    }
    bool isClicked(const sf::Vector2f &mousePos)
    {
        if(button.getGlobalBounds().contains((mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::sleep(sf::Time(sf::seconds(0.5)));
        return true;
        }
        return false;
    }
    sf::FloatRect getPos() {
        return this->button.getGlobalBounds();
    }
private:
    sf::RectangleShape button;
    sf::Text buttonText;
};

class Menu {
public:
Menu() {
this->font.loadFromFile("Fonts/times.ttf");
exitGame = Button(100.f,100.f,200.f,80.f,this->font, "EXIT");
startGame = Button(100.f,300.f,200.f,80.f,this->font, "START");;
options = Button(100.f,500.f,200.f,80.f,this->font, "OPTIONS");
achievements = Button(100.f,700.f,200.f,80.f,this->font, "ACHIEVEMENTS");
multiplayer = Button(100.f,900.f,200.f,80.f,this->font, "MULTIPLAYER");
title = Button(700.f,200.f,500.f,200.f,this->font, "GAME_TITLE");

title.setBackGroundColor(sf::Color::Black);
// title.setTextSize(sf::Vector2f(3.f,3.f));
title.setTextSize(100.f);
}
void drawMenu(sf::RenderWindow& window) {
    exitGame.draw(window);
    startGame.draw(window);
    options.draw(window);
    title.draw(window);
    achievements.draw(window);
    multiplayer.draw(window);

}
void highlight(sf::Vector2f mousePos) { //if the player cursor is hovering over a button, then there should be a highlighting of that button
    if(exitGame.getPos().contains(mousePos)) {
        exitGame.highlightButton();
    }
    else if(startGame.getPos().contains(mousePos)) {
        startGame.highlightButton();
    }
    else if(options.getPos().contains(mousePos)) {
        options.highlightButton();
    }
    else if(achievements.getPos().contains(mousePos)) {
        achievements.highlightButton();
    }
    else if(multiplayer.getPos().contains(mousePos)) {
        multiplayer.highlightButton();
    }
    else {
        exitGame.resetButton();
        startGame.resetButton();
        options.resetButton();
        achievements.resetButton();
        multiplayer.resetButton();

    }

}
void updateMenu(sf::Vector2f mousePos, sf::RenderWindow& window, bool& cond) {
    // while(!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

    // }
    if(exitGame.isClicked(mousePos)) {
        cout << "close" << endl;
        window.close();
    }
    if(startGame.isClicked(mousePos)) {
        cond = false;
                    sf::sleep(sf::Time(sf::seconds(0.5)));

    }
    if(options.isClicked(mousePos)) {

    }
}
private:
sf::Font font;
Button exitGame;
Button startGame;
Button options; 
Button title;
Button achievements;
Button multiplayer;
};

class OptionsMenu {
public:
OptionsMenu() {
this->font.loadFromFile("Fonts/times.ttf");
exitGame = Button(100.f,100.f,200.f,80.f,this->font, "EXIT GAME");
resumeGame = Button(100.f,300.f,200.f,80.f,this->font, "RESUME GAME");
options = Button(100.f,500.f,200.f,80.f,this->font, "OPTIONS");
mainMenu = Button(100.f,700.f,200.f,80.f,this->font, "MAIN MENU");
title = Button(700.f,200.f,500.f,200.f,this->font, "GAME PAUSED");
confirmation = Button(100.f,100.f,200.f,80.f,this->font, "YES");
confirmationN = Button(100.f,300.f,200.f,80.f,this->font, "NO");
titleConfirm = Button(700.f,200.f,500.f,200.f,this->font, "ARE YOU SURE YOU WANT TO GO BACK TO THE MAIN MENU?");


title.setBackGroundColor(sf::Color::Black);
// title.setTextSize(sf::Vector2f(3.f,3.f));
title.setTextSize(100.f);
}
void drawMenu(sf::RenderWindow& window) {
    exitGame.draw(window);
    resumeGame.draw(window);
    options.draw(window);
    title.draw(window);
    mainMenu.draw(window);
}
void highlight(sf::Vector2f mousePos) { //if the player cursor is hovering over a button, then there should be a highlighting of that button
    if(exitGame.getPos().contains(mousePos)) {
        exitGame.highlightButton();
    }
    else if(resumeGame.getPos().contains(mousePos)) {
        resumeGame.highlightButton();
    }
    else if(options.getPos().contains(mousePos)) {
        options.highlightButton();
    }
    else if(mainMenu.getPos().contains(mousePos)) {
        mainMenu.highlightButton();
    }
    else {
        exitGame.resetButton();
        resumeGame.resetButton();
        options.resetButton();
        mainMenu.resetButton();

    }
}
bool confirm(sf::RenderWindow& window, sf::Vector2f mousePos) {
    while(true) {
    window.clear();
    confirmation.draw(window);
    confirmationN.draw(window);
    titleConfirm.draw(window);
    window.display();

    if(confirmation.isClicked(mousePos))  {return true;}
    else if(confirmationN.isClicked(mousePos)) {return false;}
    }
}
int updateMenu(sf::Vector2f mousePos, sf::RenderWindow& window, bool& cond) {
    while(!sf::Mouse::isButtonPressed) {

    }


    if(exitGame.isClicked(mousePos)) {
        cout << "close" << endl;
        window.close();
        return 0;
    }
    else if(resumeGame.isClicked(mousePos)) {
        cond = false;
        sf::sleep(sf::Time(sf::seconds(0.5)));
        return 0;

    }
    else if(options.isClicked(mousePos)) {
        return 0;
    }
    else if(mainMenu.isClicked(mousePos)) { //go to main menu
        // if(confirm(window,mousePos)) {
        //     return 1;
        // }
        // else {
        //     cond = false;
        //     sf::sleep(sf::Time(sf::seconds(0.5)));
        //     return 0; // same as resume game
        // }
        return 1;
    }
    return 0;
}
private:
sf::Font font;
Button exitGame;
Button resumeGame;
Button options; 
Button title;
Button mainMenu;
Button confirmation;
Button confirmationN;
Button titleConfirm;

};


#endif