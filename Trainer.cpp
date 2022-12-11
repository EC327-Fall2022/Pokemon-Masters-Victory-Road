#include "Trainer.h"
#include <random>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <string>
using namespace std;

Trainer::Trainer(){
    speed = 5;
    is_at_center = false;
    is_IN_GYM = false;
    health = 20 ;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    Point2D destination;
    cout<<"Trainer default constructed."<<endl;
    state = STOPPED;
    followed1 = false;
    followed2 = false;
    num_following = 0;
}

Trainer::Trainer(char in_code){
    speed = 5;
    state = STOPPED;
    display_code = in_code;
    is_at_center = false;
    is_IN_GYM = false;
    health = 20 ;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    followed1 = false;
    followed2 = false;
    Point2D destination;
    num_following = 0;
    cout<<"Trainer constructed."<<endl;
}

Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed,
                 Point2D in_loc){
    speed = in_speed;
    name = in_name;
    is_at_center = false;
    is_IN_GYM = false;
    health = 20 ;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    location = in_loc;
    cout<<"Trainer constructed."<<endl;
    display_code = in_code;
    id_num = in_id;
    state = STOPPED;
    num_following = 0;
    followed1 = false;
    followed2 = false;
}

void Trainer::StartMoving(Point2D dest){
    SetupDestination(dest);
    if (location.x == destination.x && location.y == destination.y)
        cout<<display_code<<id_num<<" : I'm already there. See?"<<endl;
    if (HasFainted())
        cout<<display_code<<id_num<<" : My pokemon have fainted. I may move but you cannot see me."<<endl;
    else{
        if (state == IN_GYM)
            current_gym->RemoveOneTrainer();
        if (state == AT_CENTER)
            current_center->RemoveOneTrainer();
        state = MOVING;
            cout<<display_code<<id_num<< ": On my way."<<endl;
}}

void Trainer::StartMovingToGym(PokemonGym* gym){
    current_gym = gym;
    SetupDestination(gym->location);
    if (HasFainted())
        cout<<display_code<<id_num<<" : My pokemon have fainted. I can't move to the gym..."<<endl;
    if (state != IN_GYM){
        if (state == AT_CENTER){
            current_center->RemoveOneTrainer();
            }
        state = MOVING_TO_GYM;
        cout<<display_code<<id_num<<" : on my way to gym."<<(gym->id_num)<<endl;}
    else{
        state = IN_GYM;
        cout<<display_code<<id_num<<" : I am already at the PokemonGym!"<<(gym->id_num)<<endl;}
}

void Trainer::StartMovingToCenter(PokemonCenter* center){
    current_center = center;
    SetupDestination(center->location);
    if (HasFainted())
        cout<<display_code<<id_num<<" :My pokemon have fainted so I should have gone to the center..."<<endl;
    if (state != AT_CENTER ){
        if (state == IN_GYM){
            current_gym->RemoveOneTrainer ();
            }
        state = MOVING_TO_CENTER;
        cout<<display_code<<id_num<<" : On my way to center"<<(center->id_num)<<endl;}
    else{
        state = AT_CENTER;
        cout<<display_code<<id_num<<" : I am already at the Center!"<<endl;
    }
}
void Trainer::StartBattling(unsigned int num_battles){
    
    if(HasFainted())
        cout<<display_code<<id_num<<" : My Pokemon have fainted so no more battles for me..."<<endl;
    else if (state != IN_GYM)
        cout<<display_code<<id_num<<" : I can only battle in a PokemonGym!"<<endl;
    else if (PokeDollars < current_gym->GetPokeDollarCost(num_battles))
        cout<< display_code<<id_num<<" : Not enough money for battles."<<endl;
    else if(current_gym->GetNumBattlesRemaining()== 0)
        cout<<display_code<<id_num<<" : Cannot battle! This PokemonGym has no more trainers to battle!"<<endl;
    else{
        state= BATTLING_IN_GYM;
        if(current_gym->GetNumBattlesRemaining()<= num_battles)
        battles_to_buy = current_gym->GetNumBattlesRemaining();
        else{
        battles_to_buy = num_battles;}
        cout<<display_code<<"Started to battle at the PokemonGym "<<current_gym->id_num<<" with "<<battles_to_buy<<" battles."<<endl;}
    }

void Trainer::StartRecoveringHealth(unsigned int num_potions){
    if(state!=AT_CENTER)
       cout<<display_code<<id_num<<" : I can only recover health at a Pokemon Center!"<<endl;
    else if(PokeDollars < (current_center->pokedollar_cost_per_potion * num_potions))
       cout<<display_code<<id_num<<" : Not enough money to recover health."<<endl;
    else if(current_center->num_potions_remaining<1)
       cout<< display_code<<id_num<<" : Cannot recover! No potion remaining in this Pokemon Center"<<endl;
    else {
        state = RECOVERING_HEALTH;
        if (current_center->num_potions_remaining< num_potions)
            potions_to_buy = current_center->num_potions_remaining;
        else
        potions_to_buy = num_potions;
        current_center->num_potions_remaining -= potions_to_buy;
         
        cout<<display_code<<id_num<<" : Started recovering "<<num_potions << " potions at Pokemon Center"<< current_center->id_num<<endl;
        }}
        
void Trainer::Stop(){
        state = STOPPED;
        cout<<display_code<<id_num<<" : Stopping.."<<endl;
    }
bool Trainer::HasFainted(){
        if(health == 0)
            return true;
       else
            return false;
    }
bool Trainer::ShouldBeVisible(){
        if (health != 0)
            return true;
        else
            return true;
    }

void Trainer::ShowStatus(){
        cout<<name<<" status: "<<endl;
        GameObject::ShowStatus();
             cout << "being followed by " <<num_following << " wild pokemon "<<endl;
        switch (state){
            case STOPPED:{
                cout<<"stopped"<<endl;
                break;}
            case MOVING :{
                cout<<"moving at a speed of "<<speed<<" to destination "<<destination<<" at each step of "<<delta;
break;
}            case MOVING_TO_GYM:{
                cout<<"heading to PokemonGym "<<current_gym->id_num<<" at a speed of "<<speed<< " at each step of "<<delta<<endl;
break;    
      }  case MOVING_TO_CENTER:{
                cout<<"heading to Pokemon Center "<<current_center->id_num<<" at a speed of "<<speed<<" at each step of "<<delta<<endl;
break;
 }           case IN_GYM :{
                cout<<"inside PokemonGym "<<current_gym->id_num<<endl;
break;
}            case AT_CENTER:{
                cout<<"inside Pokemon Center"<<current_center->id_num<<endl;
break;}
            case BATTLING_IN_GYM :{
                cout<<"battling in PokemonGym"<<current_gym->id_num<<endl;
break;}
            case RECOVERING_HEALTH:{
                cout<<"recovering health in Pokemon Center "<<current_center->id_num<<endl;
       break; }
}
    }
bool Trainer::Update(){
        cout<<name<<" status: "<<endl;
        if (health == 0){
            cout<<name<<"is out of health and can’t move"<<endl;
            state = FAINTED;
        }
             switch (state){
            case STOPPED :{
                cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                return false;
                break;}
            case MOVING :{
                if (UpdateLocation()){
                cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                state = STOPPED;
                return true;
                }
                
                cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                return false;
                break;}                 
            case MOVING_TO_GYM :{
                if(UpdateLocation()){
                current_gym->AddOneTrainer();
                cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                state = IN_GYM;
                return true;}
                
                cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                return false; break;}
            case MOVING_TO_CENTER :{
                if (UpdateLocation()){
                current_center->AddOneTrainer();
                cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                state = AT_CENTER;
                return true;}

                cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                return false; break;}
            case IN_GYM :{
                cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                return false;
                break;}
            case AT_CENTER :{
                cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                return false;
                 break;}
            case BATTLING_IN_GYM :{
                health -= (battles_to_buy * (current_gym->health_cost_per_battle));
                PokeDollars -= (battles_to_buy * (current_gym->PokeDollar_cost_per_battle));
                experience += current_gym->TrainPokemon(battles_to_buy);

		cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                cout<<"** "<<name<<" completed "<<battles_to_buy<<" battle(s)! **"<<endl;
                cout<<"** "<<name<<" gained "<<experience<<" experience! **"<<endl;
                state = IN_GYM;
                return true;}
            case RECOVERING_HEALTH:{
                health += (5 * potions_to_buy);
                PokeDollars -= (potions_to_buy)*(current_center->pokedollar_cost_per_potion);
                cout<<"Health: "<<health<<endl;
                cout<<"PokeDollars: "<<PokeDollars<<endl;
                cout<<"Experience: "<<experience<<endl;
                cout<<"** "<<name<<" recovered "<<(5* potions_to_buy) <<" health!**"<<endl;
                cout<<"** "<<name<<" bought "<< potions_to_buy <<" potion(s)! **";
                state = AT_CENTER;
                return true;}
       default:
                return false;
        }}
        
bool Trainer::UpdateLocation(){
//Updates objects location while it is moving
    if (fabs(destination.x-location.x) <= fabs(delta.x) && fabs(destination.y-location.y) <= fabs(delta.y)){
        location = destination;
        cout<<display_code<<id_num<<" : I’m there!"<<endl;
        return true;
    }
    else{
        location.x = location.x +delta.x;
        location.y = location.y +delta.y;
        if (followed1 || followed2 ){
        if (health >= num_following*3)
        health -= num_following*3;
        else
        health = 0;
        cout << "being followed by a wild pokemon" <<endl;
        return false;
        }
      else{
        health -= 1;
        PokeDollars += GetRandomAmountOfPokeDollars();
        cout<<display_code<<id_num<<" : step…"<<endl;
        return false;
        }
}}

void Trainer::SetupDestination(Point2D dest){
     destination = dest;
     delta = (destination-location)* (speed / GetDistanceBetween(destination, location));

}
Trainer::~Trainer(){
    cout<<"Trainer destructed"<<endl;
}
string Trainer::Gettrainername(){
    return this->name;
}
double GetRandomAmountOfPokeDollars(){
    return  (rand() / (double)RAND_MAX * (2.0-0.0));
}
