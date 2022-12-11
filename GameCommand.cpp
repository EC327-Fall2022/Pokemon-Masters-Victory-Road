#include "GameCommand.h"
#include <iostream>
using namespace std;

void DoMoveCommand(Model& model, int trainer_id, Point2D p1){
    char aor;
    Trainer* trainer = model.GetTrainerPtr(trainer_id);
    if(trainer != 0 ){
        trainer->StartMoving(p1);
	cout<<"Echo: Moving "<<trainer->Gettrainername()<<" to "<<p1<<endl;
        
    }
    else
        cout<<"Error: Please enter a valid command!"<<endl;
}
void DoMoveToCenterCommand(Model & model, int trainer_id, int center_id){
    Trainer* trainer1 = model.GetTrainerPtr(trainer_id);
    PokemonCenter* pc = model.GetPokemonCenterPtr(center_id);
        if(trainer1 != 0 && pc != 0){        
	trainer1->StartMovingToCenter(pc);        
 	cout<<"Echo: Moving "<<trainer1->Gettrainername()<<" to pokemon center "<<center_id<<endl;
    }
    else
        cout<<"Error: Please enter a valid command!"<<endl;
}
void DoMoveToGymCommand(Model & model, int trainer_id, int gym_id){
    Trainer* trainer2 = model.GetTrainerPtr(trainer_id);
    PokemonGym* pg = model.GetPokemonGymPtr(gym_id);
    if(trainer2 != 0 && pg != 0){
        trainer2->StartMovingToGym(pg);
        cout<<"Echo: Moving "<<trainer2->Gettrainername()<<" to pokemon gym "<<gym_id<<endl;
    }
    else
        cout<<"Error: Please enter a valid command!"<<endl;
}
void DoStopCommand(Model & model, int trainer_id){
    Trainer* trainer3 = model.GetTrainerPtr(trainer_id);
    if(trainer3 != 0){
        cout<<"Echo: Stopping"<<trainer3->Gettrainername()<<endl;
        trainer3->Stop();
    }
    else
        cout<<"Error: Please enter a valid command!"<<endl;
}
void DoBattleCommand(Model & model, int trainer_id, unsigned int battles){
    Trainer* tr4 = model.GetTrainerPtr(trainer_id);
    if (tr4 != 0){
        tr4->StartBattling(battles);
        cout<<"Echo: "<<tr4->Gettrainername()<<" is battling."<<endl;
    }
    else
        cout<<"Error: Please enter a valid command!"<<endl;
}
void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed){
    Trainer* tr5 = model.GetTrainerPtr(trainer_id);
    if (tr5 != 0){
        tr5->StartRecoveringHealth(potions_needed);
        cout<<"Echo: "<<"Recovering "<<tr5->Gettrainername()<<"'s Pokemon’s health"<<endl;
    }
    else
        cout<<"Error: Please enter a valid command!"<<endl;
}
void DoAdvanceCommand(Model& model, View& view){
    cout<<"Echo: Advancing one tick."<<endl;
    model.Update();
    model.Display(view);
}
void DoRunCommand(Model& model, View& view){
    bool o;
    cout<<"Echo: Advancing to next event."<<endl;
    int initial_time = model.Gettime();
    do{
    o = model.Update();
    model.Display(view);
    }while(!o && (model.Gettime()-initial_time)<5);
}


