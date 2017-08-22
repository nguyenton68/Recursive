/*
08/21/2017 Eclipse
Place 8 queens in a 8x8 board
- For each row: loop all combination to see is there a solution.
- If not, move to next row.

- This sol is not so optimized: use many loops
 */

#include<iostream>
#include<vector>
using namespace std;
const int N=8;
bool checkValid(int a[N][N], int row, int col)
{
  /* In the placeQueen: the row is fixed, so column need to vary to check */
  for(int i=0; i<N; i++)
    {
      if(a[row][i]==1)
	return false;
    }

  for(int i = row, j=col; i>=0 &&j>=0; i--, j--)
    {
      if(a[i][j]==1)
	return false;
    }

  for(int i=row, j=col; i<N && j<N; i++,j++)
    {
      if(a[i][j]==1)
	return false;
    }
  return true;
}
bool placeQueen(int a[N][N], int col)
{
  if(col>=N)
    return true;

  for(int i=0; i<N; i++)
    {
      /* Check: for this ith row, is there any column cross this row available */
      if( checkValid(a,i,col))
	{
	  a[i][col]=1;
	  if( placeQueen(a,col+1))
	    return true;
	  a[i][col]=0;
	}
    }
  return false;
}
void print(int a[N][N])
{
  for(int i=0; i<N; i++)
    {
      for(int j=0; j<N; j++)
	{
	  cout<<a[i][j];
	}
      cout<<endl;
    }
}
int main()
{
int arr[N][N]=
  {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  };
  bool res = placeQueen(arr, 0);
  print(arr);
}
