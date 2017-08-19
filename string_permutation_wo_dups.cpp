/* 
08/19/2017
Find all permutation of a string
- Loop to get the first character of a new string
- Remainder is the rest of the original string - first
- The base case is Remainder=="", push back FIRST(contain all characters from original string) to a vector

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void FindPermu(string after, string before, vector<string> &res)
{
  int n=after.size();

  if(!n)
    {
      res.push_back(before);
      return;
    }
  for(int i=0; i<n; i++)
    {
      string first = before+after.substr(i,1);
      string remaind = after.substr(0,i)+after.substr(i+1,n-i-1);
      FindPermu(remaind, first, res);
    }
}
int main()
{
  vector<string> result;
  string input="abc";
  string curr="";

  FindPermu(input, curr, result);
  for(int i=0; i<result.size(); i++)
    {
      cout<<result[i]<<endl;
    }
}
