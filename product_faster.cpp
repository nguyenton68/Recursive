/*
08/18/2017
Get product of 2 number wo using * or /.
Can only use + or -
- Keep separate the smaller number into half
- Add itself twice if we reach smaller=2
- If it is smaller is odd number: half+half+large

For example:
5*7 = ((5/2)*7)*2 + 7
 */
#include<iostream>
using namespace std;

int ProductHelper(int small, int large)
{
  if(small==0)
    return 0;
  else if(small==1)
    return large;

  int tmp=small>>1;
  int halfPro = ProductHelper(tmp,large);
  if(small%2==0)
    {
      return halfPro +halfPro;
    }
  else
    {
      return halfPro+halfPro+large;
    }
}
int minProduct(int x, int y)
{
  int small = (x>y) ? y : x;
  int large =(x>y) ? x:y;
  return ProductHelper(small,large);
}
int main()
{
  int a=5,b=7;
  int sum = minProduct(a,b);
  cout<<"Product of "<<a<<" X "<<b<<" = "<<sum<<endl;
}
