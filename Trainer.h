
#ifndef TRAINER_H
#define TRAINER_H
#include "Point2D.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include <iostream>
#include <string>


enum TrainerStates {
STOPPED = 0,
MOVING = 1,
FAINTED = 2,
AT_CENTER = 3,
IN_GYM = 4,
MOVING_TO_CENTER = 5,
MOVING_TO_GYM = 6,
BATTLING_IN_GYM = 7,
RECOVERING_HEALTH = 8,
BEING_FOLLOWED = 9
};

class Trainer: public GameObject{
public:
    Trainer();
    Trainer(char in_code);
    Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
    void StartMoving(Point2D dest);
    void StartMovingToGym(PokemonGym* gym);
    void StartMovingToCenter(PokemonCenter* center);
    void StartBattling(unsigned int num_battles);
    void StartRecoveringHealth(unsigned int num_potions);
    void Stop();
    bool HasFainted();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    virtual ~Trainer();
    string Gettrainername();
    bool followed1;
    bool followed2;
    int num_following;
protected:
    bool UpdateLocation();
    void SetupDestination(Point2D dest);
private:
    double speed;
    bool is_at_center;
    bool is_IN_GYM;
    unsigned int health;
    unsigned int experience;
    double PokeDollars;
    unsigned int battles_to_buy;
    unsigned int potions_to_buy;
    std::string name;
    PokemonCenter* current_center;
    PokemonGym* current_gym;
    Point2D destination;
    Vector2D delta;
};
double GetRandomAmountOfPokeDollars();
#endif
