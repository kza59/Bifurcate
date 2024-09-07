#include <iostream>
#include "include/Game.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
int main() {
    srand(static_cast<unsigned>(time(NULL)));
    Game game;
    while(game.running()) {
        //update 
        game.update();
        //render
        game.render();
}
}