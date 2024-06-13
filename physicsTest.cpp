#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "include/Physics.h"
#include "Entity.h"


void test1() {
        std::vector<Body> bodies;

    Vector circleCenter(400, 300);
    float circleRadius = 200.0f;
    int numBalls = 30;
    float ballRadius = 10.0f;
       float ballMass = 1.0f;
    // Circle of balls
    for (int i = 0; i < numBalls; i++) {
        float angle = (2 * M_PI / numBalls) * i;
        Vector position(circleCenter.x + circleRadius * cos(angle), circleCenter.y + circleRadius * sin(angle));
        Vector velocity(15*(i+1), 15*(i+1)); 
        bodies.push_back(Body(position, velocity, ballMass));
    }
}
void run() {
            Vector collision;
                    int counter{0};
                    bool condition = false;
                    sf::Text text;
                    sf::Font font;
                    text.setString("\n\n\n\n\nCOLLISION!\n\n\n\n\n");
                    font.loadFromFile("Fonts/times.ttf");
                    text.setFont(font);
                    text.setCharacterSize(30);
                    text.setFillColor(sf::Color::White);
                    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    //generate a window
    sf::RenderWindow window(sf::VideoMode(1000, 1050), "Physics Engine Test");
    window.setPosition(sf::Vector2i(600,0));
    vector<Body> bodies;
    Vector circleCenter(400, 300);
    float circleRadius = 200.0f;
    int numBalls = 30;
    float ballRadius = 10.0f;
    float ballMass = 1.0f;
    // Circle of balls
    for (int i = 0; i < numBalls; i++) {
        float angle = (2 * M_PI / numBalls) * i;
        Vector position(circleCenter.x + circleRadius * cos(angle), circleCenter.y + circleRadius * sin(angle));
        Vector velocity(15*(i+1), 15*(i+1)); 
        bodies.push_back(Body(position, velocity, ballMass));
    }
    float deltaTime = 0.016f; // 60 fps
    float radius = 12.0f;
    // bodies.push_back(Body(Vector(100,100),Vector(0,500),1.0f));
    // bodies.push_back(Body(Vector(100,1000),Vector(0,-500),1.0f));

        while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
            case sf::Event::Closed:
                window.close();
            case sf::Event::KeyPressed:
                break;
                default:
                continue;
            }
        }
                window.clear();
        for (auto& body : bodies) {
            body.update(deltaTime);
        }
        for (size_t i = 0; i < bodies.size(); ++i) {
            for (size_t j = i + 1; j < bodies.size(); ++j) {
                if (checkCollision(bodies[i], bodies[j], radius, radius)) {
                    condition = true;
                    collision.x = (bodies[i].position.x-radius);
                    collision.y = (bodies[i].position.y-radius);
                    text.setPosition(collision.x,collision.y);
                    resolveCollision(bodies[i], bodies[j]);
                }
            }
        }
        if(condition == true) {
                    if(counter<30) {
                    window.draw(text);
                    ++counter;
                    }
                    else {
                        counter = 0;
                        condition = false;
                    }
        }
        for (const auto& body : bodies) {
            sf::CircleShape circle(radius);
            circle.setFillColor(sf::Color::White);
            circle.setPosition(body.position.x - radius, body.position.y - radius);
            window.draw(circle);
            // text.setPosition(body.position.x - radius, body.position.y - radius);
            // text.setString(to_string(body.position.x - radius) + to_string(body.position.y - radius));
            // window.draw(text);  
        }
        window.display();
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(deltaTime * 500)));
    }
}
int main() {

    run();
    
    return 0;
}
