/* 
08/20/2017
Print all combination of ( & )
- Number of closed can not be greater than number of opened
- Number of opened can not ge greater than number of brackets

 */
#include<iostream>
#include<string>
using namespace std;

void addParen(int count, int left, int right, string res)
{
  if(right>left)
    return;
  else if(left>count)
    return;
  else if(res.length() == 2*count)
    cout<<res<<endl;
  /* Add left */
  addParen(count,left+1, right, res+"(");
  /* Add right*/
  addParen(count,left, right+1, res+")");
  /* res is the value of res before added
For example
addParen(2,1,0,"(")
  addParen(2,2,0, "((")
  addParen(2,1,1,"()")*/
}
int main()
{
  string result;
  addParen(2,0,0,result);
}
