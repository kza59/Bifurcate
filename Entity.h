#ifndef ENTITY_H
#define ENTITY_H
using namespace std;
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "include/Physics.h"
#include "Item.h"
//
// Entity.h. Responsible for creation and generation of enemies and the player.
// Dependent mainly on the physics engine.
// Utilizes ECS system which depends heavily on the physics engine.
//
//
class EntityManager
{
private:
    float HP, HPreg, Dex, Atk, Def, Spd;
    string name;
    class Player
    {
        // Player()
        // {
        // }
    private:
    unordered_map<Item,int> inventory;

    };
    class Enemy
    {
        Enemy(uint8_t Type)
        {
            setType(Type);

        }
        void setType(uint8_t Type)
        {
            switch (Type)
            {
            case 0: //slime
            EnemyType = "slime";
                break;
            case 1: //skeleton
            EnemyType = "skeleton";
                break;
            case 2: //barbarian
            EnemyType = "barbarian";
                break;
            case 3: //acolyte
                break;
            case 4: //
                break;
            case 5: //
                break;
            }
        }

    private:
        string EnemyType;
    };

public:
    int entityCount{0};
    int capacity{10};
    //
    // createPlayer: creates an instance of the player class, given 8 parameters. Calls on physics engine.
    //
    void reserve()
    {
    }
    void addEntity(Vector pos, Vector vel, float m, string type, const string &name)
    {
    }
    void createEntity(const std::string &id)
    {
    }
    //
    // createPlayer: creates an instance of the player class
    //
    void createPlayer(string name, string type, float radius)
    {
        // addEntity(Vector(400, 400), Vector(0, 0), 2.0f, "Player");
    }
    //
    // createEnemy: creates an instance of the enemy class
    //
    void createEnemy(string name, string type, float radius, Vector pos)
    {
        // addEntity(pos, Vector(0, 0), 2.0f, "Enemy");
    }
    //
    // destroyEntity: destroys a an entity.
    // Params: entity ID, optional(cause of death)
    //
    void destroyEntity(string ID, string cause)
    {
    }

private:
    unordered_set<int> entities;
};

#endif