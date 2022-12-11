#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H
#include <iostream> 
#include "Trainer.h"

enum WildPokemonStates {
IN_ENVIRONMENT = 0,
DEAD = 1,
IN_TRAINER = 2,
};
using namespace std;

class WildPokemon : public GameObject{
protected:
    double attack;
    double health;
    double variant;
    bool in_combat;
    string name;
    Trainer* current_trainer;
public:
    bool following_trainer;
    void follow(Trainer* t);
    bool get_variant();
    double get_attack();
    double get_health();
    bool get_in_combat();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    bool ShouldBeVisible();
    WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc);
    WildPokemon();
    virtual ~WildPokemon();
};
#endif
