#ifndef PHYSICS_H
#define PHYSICS_H
#include <cmath>
using namespace std;
//
// Physics.h: Responsible for being the game's physics engine. When given any sort of input, will calculate the result on the screen.
//
class Vector
{
public:
    float x, y;
    Vector() : x(0), y(0) {}
    Vector(float x, float y) : x(x), y(y) {}
    //
    // Basic vector operations, including magntiude, scalar multiplication, vector multiplication, vector addition, etc
    //
    Vector operator+(const Vector &summand) const
    {
        return Vector(x + summand.x, y + summand.y);
    }
    Vector operator-(const Vector &subtractand) const
    {
        return Vector(x - subtractand.x, y - subtractand.y);
    }
    Vector operator/(const Vector &dividend) const
    {
        return Vector(x / dividend.x, y / dividend.y);
    }
    Vector operator/(float scalar) const
    {
        return Vector(x/scalar,y/scalar);
    }
    Vector operator*(const Vector &multiplicand) const
    {
        return Vector(x * multiplicand.x, y * multiplicand.y);
    }
    Vector operator*(float scalar) const
    {
        return Vector(x * scalar, y * scalar);
    }
    float dot(const Vector &dottand)
    {
        return x * dottand.x + y * dottand.y;
    }
    float mag() const
    {
        return sqrt(x * x + y * y);
    }
    Vector normalize() const{
        float m = mag();
        return Vector(x/m,y/m);
    }
};
class Body
{
    public:
    Vector position;
    Vector velocity;
    Vector acceleration;
    float mass;

    Body(Vector pos, Vector vel, float m) : position(pos),velocity(vel),mass(m) {}
    //
    // applyForce: Need to update both the x and y components of the acceleration
    //
    void applyForce(const Vector& force) {

        acceleration.x += force.x/mass;
        acceleration.y += force.y/mass;
    } 
    //
    // update: Updates the status of an individual body
    //
    void update(float changeInTime) {
        velocity.x += acceleration.x * changeInTime;
        velocity.y += acceleration.y * changeInTime;
        position.x += velocity.x*changeInTime;
        position.y += velocity.y*changeInTime;
        // acceleration = Vector(0,0);

    }
};
//
// checkCollision: If the difference between the two bodies is below a certain point then they have collided.
// Params: body 1, body 2, radius 1, radius 2
//
bool checkCollision(const Body& body1, const Body& body2, float radius1, float radius2) {
    Vector diff = body2.position - body1.position;
        float distance = diff.mag();
    if(distance < radius1+radius2) {
        cout << "\n\n\n\n\nCOLLISION!\n\n\n\n\n" << endl;
        
    }
    // cout << distance << endl;
    return distance < radius1+radius2;
}
//
// resolveCollision: If a collision occurs, update the velocities of the bodies
// Params: body 1, body 2, elasticity 
//
void resolveCollision(Body& body1, Body& body2, float elasticity = 1.5) {
    Vector collisionNormal = (body1.position - body2.position).normalize();
    Vector relativeVelocity = body1.velocity - body2.velocity;

    float velocityAlongNormal = relativeVelocity.dot(collisionNormal);


    if (velocityAlongNormal > 0) return;

    float e = elasticity;

    float j = -(1 + e) * velocityAlongNormal;
    j /= (1 / body1.mass) + (1 / body2.mass);

    Vector impulseVector(j,j);
    Vector massVector(body1.mass,body2.mass);
    Vector impulse = collisionNormal * impulseVector;
    body1.velocity = body1.velocity + (impulse / body1.mass);
    body2.velocity = body2.velocity - (impulse / body2.mass);
}
//
// generateBodies: add more bodies to the system
// Params: vector/array of bodies.
// Output: updated vector/array of bodies
//
vector<Body> generateBodies(vector<Body> bodies) {
vector<Body> updatedBodies;
return updatedBodies;
}
//
// destroyBodies: destroy some bodies in the system
// Params: vector/array of bodies.
// Output: updated vector/array of bodies
//
vector<Body> destroyBodies(vector<Body> bodies) {
vector<Body> updatedBodies;
}

#endif