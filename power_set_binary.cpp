/*
08/17/2017
Power set: write all subset of a set
- Each element can decide to YES/NO to appear in a subset. This is the same as binary number
- We can use a number (represent in binary number), which has the max binary representation = number of elements.
For example: all subset of 3 numbers: 1,2,3
Then the max number should be 2**3 (xxx) to represent all combination of 3 numbers.
 */
#include<iostream>
#include<cmath>
using namespace std;
void printPowerSet(int a[], int num_ele)
{
  int max_num_binary=pow(2,num_ele);
  for(int i=0; i<max_num_binary; i++)
    {
      for(int j=0; j<num_ele; j++)
	{
	  if(i & (1<<j))
	    cout<<a[j];
	}
      cout<<endl;
    }
}
int main()
{
  int a[3]={1,2,3};
  printPowerSet(a,3);
}
