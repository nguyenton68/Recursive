/* 08/23/2017 
 * Bolean evaluation: number of ways to combine a string consists of number and operator (&|^) to a given bolean value
 * - Use recursive call to combine the subexpression
 * - Divide into left and right and the middle is the operator
 * - Keep dividing until only 1 element left, the base case
 * - To get True for &: = leftTrue*rightTrue
 * - | = leftTrue*rightTrue+leftTrue*rightFalse+leftFalse*rightTrue
 * - ^ = leftFalse*rightTrue+leftTrue*rightFalse
 *
 * For example: eval(1|0^0)
 * left =1, right =0^0, middle ="|"
 * Next call eval(0^0)
 * left=0; right=0; middle ="^"
 */
#include<iostream>
#include<string>

using namespace std;
/* Convert string to bool */
bool string2bool(string s)
{
  if(s=="1")
    return true;
  else
    return false;
}
/* Function to evaluate the expression */
int countEval(string s, bool result)
{
  if(s.length()==0)
    return 0;
  /* Base case */
  if(s.length()==1)
    return string2bool(s)== result? 1 : 0;

  int ways=0;
  for(int i=1; i<s.length(); i+=2)
    {
      char c = s[i];
      string left = s.substr(0,i);
      string right = s.substr(i+1, s.length());

      int leftTrue =countEval(left,true);
      int leftFalse=countEval(left,false);
      int rightTrue=countEval(right,true);
      int rightFalse=countEval(right,false);
      int total=(leftTrue+leftFalse)*(rightTrue+rightFalse);

      int totalTrue=0;//total TRUE, in order to get FALSE, need to subtract from TRUE
      if(c=='^')
	{
	  totalTrue=leftTrue*rightFalse +leftFalse*rightTrue;
	}
      else if(c=='&')
	{
	  totalTrue=leftTrue*rightTrue;
	}
      else if(c=='|')
	{
	  totalTrue=leftTrue*rightTrue + leftTrue*rightFalse +leftFalse*rightTrue;
	}
      int subways = result ? totalTrue : total-totalTrue;
      ways+=subways;
    }
  return ways;
}

int main()
{
  string input="0&0&0&1^1|0";
  bool result=true;
  int res = countEval(input,result);
  cout<<"number of ways= "<<res<<endl;
}
