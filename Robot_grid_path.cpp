/* 
08/16/2017
Find path for robot on a grid: can move right and down only.
- Use stack to save the previous step
- If already find path on the left, then don't move to right
- If the grid is blocked then remove this grid from stack
*/
#include<iostream>
#include<stack>

using namespace std;
const int row=3;
const int column=4;
/* which point is allowed to cross */
int grid[row][column]=
    {
      {1,1,1,0},
      {0,1,1,1},
      {1,1,1,1}
    };
struct point
{
  int x;
  int y;
}point;
stack<struct point> ph;//to store the coordinate
bool get_path(int r, int c)
{
  struct point p;
  p.x=r;
  p.y=c;
  ph.push(p);
  bool suc=false;
  if(r==1&&c==1)
    return true;
  if(r>1&&grid[r-1][c])
    {
      suc = get_path(r-1,c);
    }
  else if(!suc &&(c>1)&&grid[r][c-1])
    {
      suc = get_path(r,c-1);
    }
  if(!suc)
    {
      ph.pop();
    }
  return suc;
}
int main()
{
  bool res = get_path(3,4);
  struct point tmp;
  while(!ph.empty())
    {
      tmp = ph.top();
      cout<<tmp.x<<"\t"<<tmp.y<<endl;
      ph.pop();
    }
}
