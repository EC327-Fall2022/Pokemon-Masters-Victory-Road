#include "WildPokemon.h"
using namespace std;

    void WildPokemon::follow(Trainer* t){
    this->current_trainer = t;
    state = IN_TRAINER;
    following_trainer = true;
    in_combat = true;
}
    bool WildPokemon::get_variant(){
    return variant;
}
    double WildPokemon::get_attack(){
    return attack;
}
    
    double WildPokemon::get_health(){
    return health;
}

    bool WildPokemon::get_in_combat(){
    return in_combat;
}

    bool WildPokemon::Update(){
    cout<<name<<" status: "<<endl;
    cout << "(" << this->location.x << "," << this->location.y << ")"<<endl;
    if(!IsAlive()){
    	state = DEAD;
        following_trainer = false;}
    switch (state){
    case IN_ENVIRONMENT:
        cout<< "is in the environment"<<endl;        
    	return false;
    case DEAD:
        cout<< "Dead"<<endl;
        return false;
    case IN_TRAINER:{
        if(this->current_trainer->HasFainted()){
        state = IN_ENVIRONMENT;
        following_trainer = false;
        cout << "is in the environment" << endl;
              return true;}
        cout << "is following trainer "<< current_trainer->GetId()<< endl; 
        this->location = current_trainer->GetLocation();
        this->health -= 1;
        cout << "In Combat with trainer: " << current_trainer->Gettrainername()<< endl;
	return false;

}
    default:
        return false; 
}
}
    void WildPokemon::ShowStatus(){
 cout << "WildPokemon status: "<<endl;
 GameObject::ShowStatus();   
if(!IsAlive())
in_combat = false; 
cout<< "W"<<this->id_num <<" in combat: " <<in_combat<< " IsAlive: " << IsAlive() <<endl;
  cout <<"Health : " << health <<endl;
        cout<< "Attack : " << attack << endl;
        cout << "Variant: " << variant << endl;
   
 }
    bool WildPokemon::IsAlive(){
    if (this->health >  0) 
    	return true;
    else 
        return false;
}
   WildPokemon::WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc){
   this->name = name;
   this->attack = attack;
   this->health = health;
   this->variant = variant;
   this->id_num = id;
   this->location = in_loc;
   state = IN_ENVIRONMENT;
   display_code = 'W';   
   in_combat = false; 
 }
  WildPokemon::WildPokemon(){
  attack = 5 ;
  health = 2;
  variant = false;
  in_combat = false;
  state = IN_ENVIRONMENT;
  display_code = 'W';
}

WildPokemon::~WildPokemon(){
cout << "Wild Pokemon Destructed" <<endl;
}

bool WildPokemon::ShouldBeVisible(){
        if (health != 0)
            return true;
        else
            return true;
}


