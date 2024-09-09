//goal: merge the functionality of the sfml rectangleshape with the custom physics engine
#ifndef PHYSICS_H
#define PHYSICS_H
#include <cmath>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
using namespace std;
//
// Physics.h: Responsible for being the game's physics engine. When given any sort of input, will calculate the result on the screen.
//
class Body
{
public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::RectangleShape bod;
    float mass;

    Body() {}
    Body(sf::Vector2f pos, sf::Vector2f vel, float m) : position(pos), velocity(vel), mass(m) {}

    float mag(sf::Vector2f v) const
    {
        return sqrt(v.x * v.x + v.y * v.y);
    }

    float dot(const sf::Vector2f &dottee,const sf::Vector2f &dottand)
    {
        return dottee.x * dottand.x + dottee.y * dottand.y;
    }
    sf::Vector2f mult(sf::Vector2f v1, sf::Vector2f v2 ) {
        return sf::Vector2f( v1.x* v2.x, v1.y * v2.y);
    }
    sf::Vector2f normalize(sf::Vector2f v) const
    {   

        float m = mag(v);
        return sf::Vector2f(v.x / m, v.y / m);
    }

    void applyForce(const sf::Vector2f &force)
    {

        acceleration.x += force.x / mass;
        acceleration.y += force.y / mass;
    }
    //
    // update: Updates the status of an individual body
    //
    void update(float changeInTime)
    {
        velocity.x += acceleration.x * changeInTime;
        velocity.y += acceleration.y * changeInTime;
        // position.x += velocity.x * changeInTime;
        // position.y += velocity.y * changeInTime;
        // acceleration = sf::Vector2f(0, 9.81f);
        // acceleration.y
    }
    // checkCollision : Checks if there are any collisions between two bodies
    bool checkCollision(const Body &body1, const Body &body2, float radius1, float radius2)
    {
        sf::Vector2f diff = body2.position - body1.position;
        float distance = mag(diff);
        if (distance < radius1 + radius2)
        {

        }
        return distance < radius1 + radius2;
    }
    // resolveCollision: If a collision occurs, update the velocities of the bodies
    // Params: body 1, body 2, elasticity
    //
    void resolveCollision(Body &body1, Body &body2, float elasticity = 1.5)
    {
        sf::Vector2f collisionNormal = normalize(body1.position-body2.position);
        sf::Vector2f relativeVelocity = body1.velocity - body2.velocity;

        float velocityAlongNormal = dot(relativeVelocity, collisionNormal);

        if (velocityAlongNormal > 0)
            return;

        float e = elasticity;

        float j = -(1 + e) * velocityAlongNormal;
        j /= (1 / body1.mass) + (1 / body2.mass);

        sf::Vector2f impulseVector(j, j);
        sf::Vector2f massVector(body1.mass, body2.mass);
        sf::Vector2f impulse = mult(collisionNormal,impulseVector);
        body1.velocity = body1.velocity + (impulse / body1.mass);
        body2.velocity = body2.velocity - (impulse / body2.mass);
    }


};

class Projectile { //Every projectile should have a damage value, a velocity, an acceleration, a position, a projectile sprite, and a mass
public:
    float projectileDamage;
    // sf::Sprite projectileSprite;
    sf::CircleShape projectileSprite;
    sf::Vector2f acceleration;
    sf::Vector2f velocity;
    sf::Vector2f position;
    float lifeTime;
    float mass;
    sf::Clock projClock;

void speedUp(double factor) {
    this->velocity.x *= factor;
    this->velocity.y *= factor;
}

    void update(float changeInTime)
    {
        velocity.x += acceleration.x * changeInTime;
        velocity.y += acceleration.y * changeInTime;
        // position.x += velocity.x * changeInTime;
        // position.y += velocity.y * changeInTime;
        // acceleration = sf::Vector2f(0, 9.81f);
        // acceleration.y
    }
    // Projectile() {
    // }
};

inline bool checkCollision2(sf::Vector2f p1, sf::Vector2f p2, float r1, float r2) {
        sf::Vector2f diff = p2 - p1;
        float distance = sqrt(diff.x * diff.x + diff.y * diff.y);

        return distance < r1 + r2;
}
#endif