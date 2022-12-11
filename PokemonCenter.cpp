#include "PokemonCenter.h"
using namespace std;

int PokemonCenter::update = 0;
PokemonCenter::PokemonCenter(){
    display_code = 'C';
    potion_capacity= 100;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = 5;
    state = POTIONS_AVAILABLE;
    cout<<"PokemonCenter default constructed"<<endl; 
}
PokemonCenter::PokemonCenter (int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc){
    location = in_loc;
    id_num = in_id;
    pokedollar_cost_per_potion = potion_cost;
    potion_capacity = potion_cap;
    num_potions_remaining = potion_cap;
    display_code = 'C';
    state = POTIONS_AVAILABLE;
    cout<<"PokemonCenter constructed"<<endl;
}
bool PokemonCenter::HasPotions(){
    if (!state)
        return true;
    else
        return false;
}
unsigned int PokemonCenter::GetNumPotionRemaining(){
    return num_potions_remaining;
}
bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget){
    if (potion * pokedollar_cost_per_potion <= budget)
        return true;
    else
        return false;
}

double PokemonCenter::GetPokeDollarCost(unsigned int potion){
    return potion * pokedollar_cost_per_potion;
}
unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed){
    if(num_potions_remaining >= potion_needed){
        num_potions_remaining -= potion_needed;
        return potion_needed;
    }
    else{
        potion_needed = num_potions_remaining;
        num_potions_remaining = 0;
        return potion_needed;
    }
}
bool PokemonCenter::Update(){
    if (num_potions_remaining == 0 && !update){
        state =  NO_POTIONS_AVAILABLE;
        display_code = 'c';
        cout<<"PokemonCenter "<<id_num<<" has ran out of potions"<<endl;
        update ++;
        return true;
    }
    else
        return false;
}
PokemonCenter::~PokemonCenter(){
    cout<<"PokemonCenter destructed"<<endl;
}
void PokemonCenter::ShowStatus(){
    cout<<"PokemonCenter status: "<<endl;
    Building::ShowStatus();
    cout<<"PokeDollars per potion: "<< pokedollar_cost_per_potion<<endl;
    cout<<"has "<<num_potions_remaining<< " potion(s)remaining."<<endl;
}

