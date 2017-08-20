/*
08/18/2017
Find all permutation of a string
- Use hash table: put in the key (char) and value( how many dups of that char).
- Loop through hash table: get char at [i], add into f string, decrease count of that char in hash table.
- Call the FindPermu
- Increase the count for the char

Caution:
- How to insert new element into hash table (map)
- How to access the first and second element of a map.
- Keep track of counting
 */
#include<iostream>
#include<vector>
#include<map>

using namespace std;
void FindPermu(string curr, map<char, int> m, vector<string> &res, int n)
{
  int curr_length = curr.length();
  /* Base case */
  if(curr_length == n)
    {
      res.push_back(curr);
      return;
    }
  /* Loop through the hash table */
  for(map<char, int>::iterator i=m.begin(); i != m.end(); i++)
    {
      if(i->second != 0)
	{
	  char c = i->first;
	  string f = curr+c;
	  i->second--;
	  FindPermu(f, m, res, n);
	  i->second++;
	}
    }
}
int main()
{
  string input="aab";
  string curr="";
  map<char, int> m;
  int n=input.length();
  /* Create a hash table with char (->first) and number of dups of that char (->second) */
  for(int i=0; i<n; i++)
    {
      if(m.find(input[i]) != m.end())
	m.find(input[i])->second++;
      else
	m.insert(pair(input[i],1));
    }
  vector<string> res;
  FindPermu(curr, m, res, n);
  for(int i=0; i<res.size(); i++)
    {
      cout<<res[i]<<endl;
    }
}
