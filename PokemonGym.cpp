#include "PokemonGym.h"
using namespace std;

int PokemonGym::update1 = 0;
PokemonGym::PokemonGym(){
    display_code = 'G';
    state = NOT_DEFEATED;
    max_number_of_battles = 1;
    num_battle_remaining = max_number_of_battles;
    health_cost_per_battle = 1;
    PokeDollar_cost_per_battle = 1.0;
    experience_per_battle = 2;
    cout<<"PokemonGym default constructed"<<endl;}
PokemonGym::PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc){
    id_num = in_id;
    max_number_of_battles = max_battle;
    health_cost_per_battle = health_loss;
    experience_per_battle = exp_per_battle;
    PokeDollar_cost_per_battle = PokeDollar_cost;
    location = in_loc;
    num_battle_remaining = max_battle;
    display_code = 'G';
    cout<<"PokemonGym constructed"<<endl;
    }
double PokemonGym::GetPokeDollarCost(unsigned int battle_qty){
    return (PokeDollar_cost_per_battle * battle_qty);
}
unsigned int PokemonGym::GetHealthCost(unsigned int battle_qty){
    return (health_cost_per_battle * battle_qty);
}
unsigned int PokemonGym::GetNumBattlesRemaining(){
    return num_battle_remaining;
}
bool  PokemonGym::IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health){
    if (budget >= (battle_qty * PokeDollar_cost_per_battle) && health >= (health * health_cost_per_battle))
        return true;
    else
        return false;
}
unsigned int PokemonGym::TrainPokemon(unsigned int battle_units){
    if(num_battle_remaining >= battle_units)
        num_battle_remaining -= battle_units;
    else
        battle_units = num_battle_remaining;
    return (experience_per_battle * battle_units);
}
unsigned int PokemonGym::GetExperiencePerBattle(){
    return experience_per_battle;
}
bool PokemonGym::Update(){
    if(num_battle_remaining == 0 && !update1){
        state = DEFEATED;
        display_code = 'g';
        cout <<display_code<<id_num<<"has been defeated"<<endl;
        update1++;
        return true;
    }
    else
        return false;
}
bool PokemonGym::passed(){
    if(num_battle_remaining == 0)
        return true;
    else
        return false;
}
void PokemonGym::ShowStatus(){
    cout<<"PokemonGymStatus: "<<endl;
    Building::ShowStatus();
    cout<<"Max number of battles: "<<max_number_of_battles<<endl;
    cout<<"Health cost per battle: "<<health_cost_per_battle<<endl;
    cout<<"PokeDollar per battle: "<<PokeDollar_cost_per_battle<<endl;
    cout<<"Experience per battle: "<<experience_per_battle<<endl;
    cout<< num_battle_remaining<<" battle(s) are remaining for this PokemonGym"<<endl;
}
PokemonGym::~PokemonGym(){
    cout<<"PokemonGym destructed"<<endl;
}
