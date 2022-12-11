#include "Building.h"
#include <iostream>
using namespace std;
Building::Building(){
    display_code = 'B';
    trainer_count = 0;
    cout<<"Building default constructed"<<endl;
}Building::Building(char in_code, int in_id, Point2D in_loc){
    id_num= in_id;
    location = in_loc;
    display_code = in_code;
    cout<<"Building constructed"<<endl;
    trainer_count=0;
}

void Building::AddOneTrainer(){
    trainer_count += 1;
}

void Building::RemoveOneTrainer(){
    trainer_count -= 1;
}

void Building::ShowStatus(){
    cout<<display_code<<id_num<<" located at"<<location<<endl;
    if (trainer_count == 1)
        cout<<trainer_count<<" trainer is in the building"<<endl;
    else
        cout<<trainer_count<<" trainers are in the building"<<endl;
}
bool Building::ShouldBeVisible(){
    return true;
}
Building::~Building(){
}
