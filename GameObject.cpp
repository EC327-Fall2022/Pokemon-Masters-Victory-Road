#include "GameObject.h"

GameObject::GameObject(){
      state= 0;
}

GameObject::GameObject(char in_code){
    display_code = in_code;
    id_num = 1;
    state = 0;
    cout<<"GameObject constructed"<<endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code){
    state = 0;
    display_code = in_code;
    location = in_loc;
    id_num = in_id;
    cout<<"GameObject constructed"<<endl;
}

Point2D GameObject:: GetLocation(){
    return this -> location;
}

int GameObject:: GetId(){
    return this -> id_num;
}

char GameObject:: GetState(){
    return this -> state;
}

void GameObject::ShowStatus(){
    cout <<display_code<<id_num<<" at "<<location<<endl;
}

GameObject::~GameObject(){ 
    cout<<"GameObject destructed"<<endl;
}

void GameObject::DrawSelf(char* ptr){
*ptr = display_code;
ptr[1] = '0' + id_num;
}

