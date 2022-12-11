#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include "Trainer.h"
#include "WildPokemon.h"
#include "View.h"
#include <list>
class Model{
private:
    int time;
    list<GameObject*>object_ptrs;
    list<GameObject*>active_ptrs;
    list<Trainer*>trainer_ptrs;
    list<PokemonGym*>gym_ptrs;
    list<PokemonCenter*>center_ptrs;
    list<WildPokemon*>wildpokemon_ptrs;

public:
WildPokemon* w1;
WildPokemon* w2;    
Trainer* t1;
Trainer* t2;
PokemonCenter* c1;
PokemonCenter* c2;
PokemonGym* g1;
PokemonGym* g2;
    Model();
    ~Model();
    Trainer* GetTrainerPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
    int Gettime();
void Trainer_in_wild();    
};
#endif

