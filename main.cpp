#include <iostream>
#include "GameCommand.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Input_Handling.h"
#include <string>
using namespace std;

int main() {
    srand(time(0));
    string command  =  "." ;
    string save = "s";
    int a,b,c;
    Model m;
    bool input = true;
    View v;
    
       while (command[0] != 'q'){
        
       
       v.Clear();
       m.ShowStatus();
       m.Display(v);
       v.Draw();

      
     do {
     cout << "Enter a command: " <<endl;
     
     if(cin >> command)
     save = command [0];
        
                
          try {
          if (!(save == "n" || save == "m" || save == "c" || save == "g" || save == "s" || save ==  "p" || save == "b" || save  == "q" || save == "a" || save == "r")){
            cin.ignore(10000, '\n');
            input = false;	
            throw Invalid_Input("Not a  command");
       }
        break;
          }           
                catch (Invalid_Input& except){
                cout << "Invalid input- " <<except.msg_ptr <<endl;
                
}} while(!input);
          
             
           switch(command[0]){
            case 'm':{               
                cin >> a >>b >>c ;
                Point2D pm(b,c);
                DoMoveCommand(m,a,pm);
                cout<<"Enter a command: "<<endl;
                cin>>command[0];
                if(command[0] == 'a')
                DoAdvanceCommand(m,v);
                else if(command[0] == 'r')
                DoRunCommand(m,v);
                break;}
            case 'c':{
                cin>>a>>b;
                DoMoveToCenterCommand(m,a,b);
                cout<<"Enter a command: "<<endl;
                cin>>command[0];
                if(command[0] == 'a')
                DoAdvanceCommand(m,v);
                else if(command[0] == 'r')
                DoRunCommand(m,v);
                break;}
            case 'g':{
                cin>>a>>b;
                DoMoveToGymCommand(m,a,b);
                cout<<"Enter a command: "<<endl;
                cin>>command[0];
                if(command[0] == 'a')
                DoAdvanceCommand(m,v);
                else if(command[0] == 'r')
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
                cin>>command[0];
                if(command[0] == 'a')
                DoAdvanceCommand(m,v);
                else if(command[0] == 'r')
                DoRunCommand(m,v);
                break;}
            case 'b':{
                cin>>a>>b;
                DoBattleCommand(m,a,b);
                cout<<"Enter a command: "<<endl;
                cin >> command[0];
                if(command[0] == 'a')
                DoAdvanceCommand(m,v);
                else if(command[0] == 'r')
                DoRunCommand(m,v);
                break;}
            case 'a':{
                DoAdvanceCommand(m,v);
                break;}
            case 'r':{
                DoRunCommand(m,v);
                break;}
            case 'n':{
                m.NewCommand();
                break;
                
            }
            case 'q':
                break;
            default:
               break;
       }
     }

    return 0;
}


