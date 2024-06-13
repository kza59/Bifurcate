#ifndef ENTITY_H
#define ENTITY_H
using namespace std;
#include <iostream>
#include "include/Physics.h"
//
// Entity.h. Responsible for creation and generation of enemies and the player. 
// Dependent mainly on the physics engine.
//
class Entity{
private:
    class Player{
        private:
        int hp;
        int atk;
        int mp;
        int dex;
        int def;
        int wis;
        int vit;
        int spd;
        public:

    };
    class Enemy{
        private:
        int hp;
        int atk;
        int mp;
        int dex;
        int def;
        int wis;
        int vit;
        int spd;
        public:


    };
public:
    //
    // createPlayer: creates an instance of the player class, given 8 parameters. Calls on physics engine.
    //
    void createPlayer() {
        
    }
    //
    // createEnemy: creates an instance of the enemy class, given the 8 stat parameters. Calls on physics engine.
    //
    void createEnemy() {

    }
    //
    // destroyEntity: destroys a an entity.
    // Params: entity ID, optional(cause of death)
    //
    void destroyEntity(string ID, string cause) {   

    }

};



#endif