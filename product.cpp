/*
08/18/2017
Get product of 2 number wo using * or /.
Can only use + or -
- Keep separate the smaller number into half
- Add itself twice if we reach smaller=2
- If it is an odd number, then call ProductHelper(smaller-smaller/2,large)

 */
#include<iostream>
using namespace std;
int ProductHelper(int small, int large)
{
  if(small==0)
    return 0;
  if(small==1)
    return large;

  int tmp=small>>1;
  int side1 = ProductHelper(tmp,large);
  int side2 = side1;
  if(small%2==1)
    {
      side2 = ProductHelper(small-tmp,large);
    }
  return side1+side2;
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
