#include <iostream>
#include "GameCommand.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Input_Handling.h"
using namespace std;

int main() {
    srand(time(0));
    char command = 'w';
    int a,b,c;
    bool input = false;
    Model m;
    View v;

       while (command != 'q'){
       v.Clear();
       m.ShowStatus();
       m.Display(v);
       v.Draw();
       
    while(!input){
        input = true;
        cout << "Enter a command: " << endl;
        cin >> command;
        cin.ignore();
        try {
          if (!(command == 'm' || command == 'c' || command == 'g' || command == 's' || command ==  'p' || command == 'b' || command == 'q' || command == 'a' || command == 'r')){
         	input = false; 
          	throw Invalid_Input("Not a  command");
       }
          else 
          	break;
       }
          catch (Invalid_Input& except){
       		cout << "Invalid input- " <<except.msg_ptr <<endl;
       }}
        
           
           switch(command){
            case 'm':{               
                cin >> a >>b >>c ;
                Point2D pm(b,c);
                DoMoveCommand(m,a,pm);
                cout<<"Enter a command: "<<endl;
                cin>>command;
                if(command == 'a')
                DoAdvanceCommand(m,v);
                else if(command == 'r')
                DoRunCommand(m,v);
                break;}
            case 'c':{
                cin>>a>>b;
                DoMoveToCenterCommand(m,a,b);
                cout<<"Enter a command: "<<endl;
                cin>>command;
                if(command == 'a')
                DoAdvanceCommand(m,v);
                else if(command == 'r')
                DoRunCommand(m,v);
                break;}
            case 'g':{
                cin>>a>>b;
                DoMoveToGymCommand(m,a,b);
                cout<<"Enter a command: "<<endl;
                cin>>command;
                if(command == 'a')
                DoAdvanceCommand(m,v);
                else if(command == 'r')
                DoRunCommand(m,v);
                break;}
            case 's':{
                cin>>a;
                DoStopCommand(m,a);
                break;}
            case 'p':{
                cin>>a>>b;
                DoRecoverInCenterCommand(m,a,b);
                cout<<"Enter a command: "<<endl;
                cin>>command;
                if(command == 'a')
                DoAdvanceCommand(m,v);
                else if(command == 'r')
                DoRunCommand(m,v);
                break;}
            case 'b':{
                cin>>a>>b;
                DoBattleCommand(m,a,b);
                cout<<"Enter a command: "<<endl;
                cin >> command;
                if(command == 'a')
                DoAdvanceCommand(m,v);
                else if(command == 'r')
                DoRunCommand(m,v);
                break;}
            case 'a':{
                DoAdvanceCommand(m,v);
                break;}
            case 'r':{
                DoRunCommand(m,v);
                break;}
            case 'q':
                break;
            default:
               break;
       }

     }

    return 0;
}


