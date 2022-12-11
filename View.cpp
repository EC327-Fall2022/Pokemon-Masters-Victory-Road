#include "View.h"
using namespace std;
int out_x, out_y;

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location){
    
    out_x = static_cast<int>(location.x-origin.x)/scale;
    out_y = static_cast<int>(location.y-origin.y)/scale;
    
    if(out_x<=((size-1)*scale) && out_y<=((size-1)*scale))
        return true;
    else
        cout<<"An object is outside the display"<<endl;
        return false;
    
}

View::View(){        
    size = 11;
    scale = 2;
    origin.x = 0;
    origin.y = 0;
}

void View::Clear(){
        
for (int i =0; i < size ; i++){
for(int j = 0; j < size; j++){
grid[i][j][0] ='.';
grid[i][j][1] =' ';
}               }
}

void View::Plot(GameObject* ptr){
        
if (GetSubscripts(out_x,out_y,ptr->GetLocation())  && (grid[out_x][out_y][0] == '.'||grid[out_x][out_y][1] == ' ')|| (grid[out_x][out_y][0] == 'W' ))
    ptr->DrawSelf(grid[out_x][out_y]);
    else {
    grid[out_x][out_y][0] = '*';
    grid[out_x][out_y][1] = ' ';
}
}


void View::Draw()
{
for(int j= size-1; j>=-1; j--)
{
for(int i = -1; i<=size-1;i++)
{
if(i==-1&&j%2==0)
{
cout<<j*2;
if(j/5==0)
{
cout<<" ";
}}
else if(i == -1 && j%2 != 0)
{
cout<<"  ";
}
else if(j==-1&&i%2==0)
{
cout<<i*2;
if(i/5 == 0)
{
cout<<" ";
}
cout<<"  ";
}
if(i>=0&&j>=0)
{
cout<<grid[i][j][0]<<grid[i][j][1];
}
}
cout<<endl;
}}








