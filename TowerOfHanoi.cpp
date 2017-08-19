/*
08/19/2017
Tower of Hanoi
- Can move 1 disk from Origin stack to Destination stack, simple
- Can move 2 disks from Origin stack to Destination stack:
Orig(2,1) -- Buf(0) -- Dest(0)
Orig(2)   -- Buf(1) -- Dest(0)
Orig(0)   -- Buf(1) -- Dest(2)
Orig(0)   -- Buf(0) -- Dest(2,1)

- Call Hanoi( A, B, C, 2): will move 2(n-1) elements from A to C
- Call Hanoi( A, B, C, 1): will move 1 element from A to C.
 */
#include<iostream>
#include<stack>

using namespace std;
void Hanoi(stack<int> &orig, stack<int> &buf, stack<int> &dest, int num)
{
  /* Move 1 disk from ORIG to DEST*/
  if(num==1)
    {
      int tmp = orig.top();
      orig.pop();
      dest.push(tmp);
      return;
    }
  /* Move 2 disks from ORIG to DEST*/
  else if(num==2)
    {
      int tmp = orig.top();
      orig.pop();
      buf.push(tmp);
      
      tmp = orig.top();
      orig.pop();
      dest.push(tmp);

      tmp = buf.top();
      buf.pop();
      dest.push(tmp);

      return;
    }
  /* Move n-1 disks from ORIG to BUF*/
  Hanoi(orig, dest, buf, num-1);
  /* Move the largest disk from ORIG to DEST*/
  Hanoi(orig, buf, dest, 1);
  /* Move n-1 disks from BUF to DEST*/
  Hanoi(buf, orig, dest, num-1);
}
int main()
{
  stack<int> origin, buffer, destination;
  origin.push(4);
  origin.push(3);
  origin.push(2);
  origin.push(1);
  Hanoi(origin, buffer, destination,4);
}
