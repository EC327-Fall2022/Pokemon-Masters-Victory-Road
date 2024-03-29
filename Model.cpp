#include "Model.h"
#include <ctime>
#include <list>
#include "Input_Handling.h"
using namespace std;

Model::Model(){
    time = 0;
    Point2D pt1(5,1);
    t1 = new Trainer("Ash",1,'T',1,pt1);
    object_ptrs.push_back(t1);
    trainer_ptrs.push_back(t1);
    active_ptrs.push_back(t1);
    Point2D pt2(10,0);
    t2 = new Trainer("Misty",2,'T',2,pt2);
    object_ptrs.push_back(t2);
    trainer_ptrs.push_back(t2);
    active_ptrs.push_back(t2);
    Point2D pc1(1,20);
    c1 = new PokemonCenter(1,1,100,pc1);
    object_ptrs.push_back(c1);
    center_ptrs.push_back(c1);
    active_ptrs.push_back(c1);
    Point2D pc2(10,20);
    c2 = new PokemonCenter(2,2,200,pc2);
    object_ptrs.push_back(c2);
    center_ptrs.push_back(c2);
    active_ptrs.push_back(c2);
    Point2D pg1(0,0);
    g1 = new PokemonGym(10,1,2,3,1,pg1);
    object_ptrs.push_back(g1);
    gym_ptrs.push_back(g1);
    active_ptrs.push_back(g1);
    Point2D pg2(5,5);
    g2 = new PokemonGym(20,5,7.5,4,2,pg2);
    object_ptrs.push_back(g2);
    gym_ptrs.push_back(g2);
    active_ptrs.push_back(g2);
    Point2D wp1(10,12);
    w1 = new WildPokemon("WildPokemon1",5,2 ,false, 1, wp1);
    wildpokemon_ptrs.push_back(w1);
    object_ptrs.push_back(w1);
    active_ptrs.push_back(w1);
    Point2D wp2(15,5);
    w2 = new WildPokemon("WildPokemon2" ,5,2,false, 2, wp2);
    object_ptrs.push_back(w2);
    wildpokemon_ptrs.push_back(w2);
    active_ptrs.push_back(w2);
    cout<<"Model default constructed"<<endl;
}

Model::~Model(){
    delete w2;
    delete w1;
    delete t1;
    delete t2;
    delete c1;
    delete c2;
    delete g1;
    delete g2;
    cout<<"Model destructed."<<endl;
}

Trainer* Model::GetTrainerPtr(int id){
    Trainer* found_trainer;
    list <Trainer*>::iterator iterT;
    for(iterT = trainer_ptrs.begin() ; iterT != trainer_ptrs.end() ; iterT++){
        if ((*iterT)->GetId() == id){
            found_trainer = *iterT;
            return found_trainer;
        }
            }
    return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id){
    PokemonCenter* found_pokemoncenter;
    list <PokemonCenter*>::iterator iterC;
    for(iterC = center_ptrs.begin() ; iterC != center_ptrs.end() ; iterC++){
        if((*iterC)->GetId() == id){
            found_pokemoncenter = *iterC;
            return found_pokemoncenter;
        }
    }
    return 0;
}

PokemonGym* Model::GetPokemonGymPtr(int id){
    PokemonGym* found_pokemongym;
    list <PokemonGym*>::iterator iterG;
    for(iterG = gym_ptrs.begin() ; iterG != gym_ptrs.end() ; iterG++){
        if((*iterG)->GetId() == id){
            found_pokemongym = *iterG;
             return found_pokemongym;;
        }
    }
    return 0;
}

bool Model::Update(){
    time += 1;
    bool updates;
    list <GameObject*>::iterator iter;
    list <GameObject*>::iterator loci;
     for (iter = active_ptrs.begin(); iter != active_ptrs.end() ; iter++){
         if (*iter == *(trainer_ptrs.begin()) || *iter == (*(++trainer_ptrs.begin()))){
         updates = (*iter)->Update();
         Trainer_in_wild();
             if((*trainer_ptrs.begin())->HasFainted()){
                 loci = iter;
                 active_ptrs.remove(*trainer_ptrs.begin());
                 iter = loci;
                 cout << "Dead object removed" <<endl;}
             if((*++trainer_ptrs.begin())->HasFainted()){
                 loci = iter;
                 active_ptrs.remove(*(++trainer_ptrs.begin()));
                 iter = loci;
                 cout << "Dead object removed" << endl;}
             if(updates)
                 return true;
            }
            if (*iter == (*wildpokemon_ptrs.begin()) || *iter == *(++wildpokemon_ptrs.begin())){
                updates = (*iter)->Update();
            if(!((*wildpokemon_ptrs.begin())->IsAlive())){
                loci = iter;
                active_ptrs.remove(*wildpokemon_ptrs.begin());
                cout << "Dead object removed" << endl;
                iter = loci;
                return true;}
            if(!(*(++wildpokemon_ptrs.begin()))->IsAlive()){
                loci = iter;
                active_ptrs.remove(*(++wildpokemon_ptrs.begin()));
                cout << "Dead object removed" << endl;
                iter = loci;
                return true;      
                 }
            
             }
                 
         else if ((*iter)->Update())
         	return true;
  
 }
     if (!(g1->GetNumBattlesRemaining()) && !(g2->GetNumBattlesRemaining())){
      cout<<"GAME OVER: You win! All battles done!"<<endl;
         exit(0);
     }

     if(t1->HasFainted() && t2->HasFainted()){
     cout<<"GAME OVER: You lose! All of your Trainers’ pokemon have fainted!"<<endl;
     exit(0);
     }
    
      else
        return false;

    }

                                      
                                      
void Model::Display(View& view) {
    list <GameObject*>::iterator iter1;
    for (iter1 = active_ptrs.begin(); iter1 != active_ptrs.end() ; iter1++){
      if (*iter1 ==  *(trainer_ptrs.begin()) || *iter1 == *(++trainer_ptrs.begin()) )
        {
        if(!(GetTrainerPtr((*iter1)->GetId())->HasFainted()))
        view.Plot(*iter1);
        }
      else if(*iter1 == *(wildpokemon_ptrs.begin())) {
         if((*wildpokemon_ptrs.begin())->IsAlive() && !((*wildpokemon_ptrs.begin())->following_trainer))
             view.Plot(*iter1);
        }
      else if(*iter1 == *(++wildpokemon_ptrs.begin())){
         if((*(++wildpokemon_ptrs.begin()))->IsAlive() && !((*(++wildpokemon_ptrs.begin()))->following_trainer))
             view.Plot(*iter1);
	}
      else
         view.Plot(*iter1);

}}

void Model::ShowStatus(){
    cout<<"Time: "<<time<<endl;
    list <GameObject*>::iterator iter2;
    for (iter2 = object_ptrs.begin(); iter2 != object_ptrs.end(); iter2++){
        (*iter2)->ShowStatus();
    }
}
int Model::Gettime(){
return time;
}
void Model::Trainer_in_wild(){
if ((*++trainer_ptrs.begin())->GetLocation().x == (*++wildpokemon_ptrs.begin())->GetLocation().x && (*++trainer_ptrs.begin())->GetLocation().y == (*++wildpokemon_ptrs.begin())->GetLocation().y && !((*++wildpokemon_ptrs.begin())->following_trainer)){
            (*++trainer_ptrs.begin())->followed2 = true;
            (*++wildpokemon_ptrs.begin())->follow(*(++trainer_ptrs.begin()));
}
if ((*++trainer_ptrs.begin())->GetLocation().x == (*wildpokemon_ptrs.begin())->GetLocation().x && (*++trainer_ptrs.begin())->GetLocation().y == (*wildpokemon_ptrs.begin())->GetLocation().y && !(*wildpokemon_ptrs.begin())->following_trainer)
{
        (*++trainer_ptrs.begin())->followed1 = true;
        (*wildpokemon_ptrs.begin())->follow(*(++trainer_ptrs.begin()));
}
if ((*trainer_ptrs.begin())->GetLocation().x == (*wildpokemon_ptrs.begin())->GetLocation().x && (*trainer_ptrs.begin())->GetLocation().y == (*wildpokemon_ptrs.begin())->GetLocation().y && !((*wildpokemon_ptrs.begin())->following_trainer))
{
        (*trainer_ptrs.begin())->followed1 = true;
        (*wildpokemon_ptrs.begin())->follow(*(++trainer_ptrs.begin()));
}

if ((*trainer_ptrs.begin())->GetLocation().x == (*++wildpokemon_ptrs.begin())->GetLocation().x && (*trainer_ptrs.begin())->GetLocation().y == (*++wildpokemon_ptrs.begin())->GetLocation().y && !((*++wildpokemon_ptrs.begin())->following_trainer))
{
       (*trainer_ptrs.begin())->followed2 = true;
       (*++wildpokemon_ptrs.begin())->follow(*(++trainer_ptrs.begin()));
}
list <Trainer*>::iterator iter3;                    
for(iter3 = trainer_ptrs.begin(); iter3 != trainer_ptrs.end() ; iter3++){
if ((*iter3)->followed2 && (*iter3)->followed1)
(*iter3)->num_following = 2;
else if ((*iter3)->followed2 || (*iter3)->followed1)
(*iter3)->num_following = 1;
}
}

void Model::NewCommand(){

char type;
int iden;
int loc_x;
int loc_y;
bool valid = true;

cin >> type >> iden >> loc_x >> loc_y;

try {
if (! (type == 'c' || type == 'g' ||type == 't' || type == 'w'))
{
valid = false;
throw Invalid_Input("Not an object type");
}
if (iden > 9)
throw Invalid_Input("maximum number of this object, can't create more");
if (type == 'w')
{
list <WildPokemon*>::iterator iw;
for (iw = wildpokemon_ptrs.begin() ; iw != wildpokemon_ptrs.end() ; iw++){
if ((*iw)->GetId() == iden){
valid = false;
throw Invalid_Input("Existing Id");
}
}
if(valid && !(loc_x > 20 || loc_x <0 || loc_y >20 || loc_y<0))
{
WildPokemon* wx; 
Point2D  pwx(loc_x, loc_y);
wx = new WildPokemon("user's wild pokemon", 5,2,false,iden, pwx);
wildpokemon_ptrs.push_back(wx);
object_ptrs.push_back(wx);
active_ptrs.push_back(wx);

}
else{
valid = false;
throw Invalid_Input("Not a valid grid location");
} 

}
if (type == 'c')
{
list <PokemonCenter*>::iterator ic;
for (ic = center_ptrs.begin() ; ic != center_ptrs.end() ; ic++){
if ((*ic)->GetId() == iden){
valid = false;
throw Invalid_Input("Existing Id");
}}
if(valid && !(loc_x > 20 || loc_x <0 || loc_y >20 || loc_y<0))
{
PokemonCenter* cx;
Point2D pcx(loc_x,loc_y);
cx = new PokemonCenter(iden, 1, 10, pcx);
object_ptrs.push_back(cx);
center_ptrs.push_back(cx);
active_ptrs.push_back(cx);
}
else{
valid = false;
throw Invalid_Input("Not a valid grid location");
}
}
if (type == 'g')
{
list <PokemonGym*>::iterator ig;
for (ig= gym_ptrs.begin() ; ig != gym_ptrs.end() ; ig++){
if ((*ig)->GetId() == iden){
valid = false;
throw Invalid_Input("Existing Id");
}
}
if(valid && ! (loc_x > 20 || loc_x <0 || loc_y >20 || loc_y<0)){
PokemonGym* gx;
Point2D  pgx(loc_x,loc_y);
gx = new PokemonGym(5, 2, 3, 1, iden, pgx);
object_ptrs.push_back(gx);
gym_ptrs.push_back(gx);
active_ptrs.push_back(gx);

}
else{
valid = false;
throw Invalid_Input("Not a valid grid location");
}
}

if (type == 't')
{
list < Trainer*> :: iterator it;
for (it = trainer_ptrs.begin() ; it != trainer_ptrs.end() ; it++){
if((*it)->GetId() == iden){
valid = false;
throw Invalid_Input("Existing Id");
}}
if (valid && ! (loc_x > 20 || loc_x <0 || loc_y >20 || loc_y<0)){
Trainer* tx;
Point2D ptx(loc_x, loc_y);
tx = new Trainer("User's trainer", iden, 'T' , 1, ptx);
object_ptrs.push_back(tx);
trainer_ptrs.push_back(tx);
active_ptrs.push_back(tx);
}
else{
valid = false;
throw Invalid_Input("Not a valid grid location");
}
}}
 catch (Invalid_Input& except){
                cout << "Invalid input- " <<except.msg_ptr <<endl;
       }

}
