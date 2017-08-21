/*
08/20/2017
Count number of ways to get n cents from combination of 5,10,25 cents
- [5, 10, 25]
- Get number of ways with 5 first
- Then number of ways with (n-10*i)%5==0
 */
#include<iostream>
#include<vector>

using namespace std;
int ways(int amount, vector<int> denom)
{
  int n=denom.size();
  if(n==1) // base case
    {
      if(amount%denom[0])
	return 0;
      else
	return 1;
    }
  int curr = denom[n-1];
  denom.pop_back();
  int sum=0;
  /* Get number of ways with only the first element in vector [0]*/
  sum+=ways(amount, denom);
  /* Loop through to get sum -[1] */
  while(amount>curr)
    {
      sum+=ways(amount-curr,denom);
      amount = amount-curr;
    }
  return sum;
}
int main()
{
  vector<int> denom;
  denom.push_back(5);
  denom.push_back(10);
  denom.push_back(25);

  int numOfWays=ways(50,denom);
  cout<<"Number of ways to get 50 cents= "<<numOfWays<<endl;
}
