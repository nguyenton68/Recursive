/*
08/15/2017
Triple step:
how many step a person need to take to go upstair which has n steps.
And he can jump 1 or 2 or 3.
- At step 5th, numOfPath(5th) =numOfPath(4th)+numOfPath(3rd)+numOfPath(2nd)
- Use array to store the (i-1)th, (i-2)th and (i-3)th path.
 */
#include<iostream>

using namespace std;
int main()
{
  int N=6;
  int arr[N];
  /* For 3 steps*/
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;
  for(int i=4; i<N; i++)
    {
      arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }

  /* For N steps stair and maximum M steps each time*/
  int n=8, m=3;
  int nstep[N];
  nstep[0]=1;
  nstep[1]=1;
  for(int i=2; i<N; i++)
    {
      nstep[i]=0;
      for(int j=1; j<=i && j<=m;j++)
	{
	  nstep[i]+=nstep[i-j];
	}
    }
  cout<<"number of steps= "<<nstep[N-1]<<endl;
}
