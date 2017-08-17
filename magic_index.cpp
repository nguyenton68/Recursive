/*
 * 08/16/2017
 * Find magic number with unique and duplicate numbers.
 * Unique: compare the middle value: if a[mid]<mid, look at right
 * Duplicate: look at both left and right
 * - For the left: min(start,mid-1)
 * - For the right: max(mid+1,end)
 */
#include<iostream>
#include<algorithm>
using namespace std;

int a[11]={-10,-5,2,2,2,3,4,7,9,12,13};
/* Function to find magic index with assumption that each integer is distinct*/
int findIndex(int start, int end)
{
  int mid=(start+end)/2;
  if(a[mid]==mid)
    return mid;
  else if(a[mid]<mid)
    {
      return findIndex(mid+1,end);
    }
  else
      return findIndex(start,mid-1);
}
/* Function to find magic index, where it can have duplicate numbers*/
int findDup(int start, int end)
{
  /* Without this condition, it causes segmentation fault */
  if(end<start)
    return -1;

  int mid=(start+end)/2;
  int midValue = a[mid];
  
  if(midValue==mid)
    return mid;

  int leftIndx = min(midValue,mid-1);
  if(findDup(start,leftIndx)>1)
    return findDup(start,leftIndx);

  int rightIndx = max(mid+1,midValue);
  if(findDup(rightIndx,end)>1)
    return findDup(rightIndx,end);

}
int main()
{
  int magic = findIndex(0,11);
  cout<<"magic index= "<<magic<<endl;
  int magicFast = findDup(0,11);
  cout<<"magic fast index= "<<magicFast<<endl;
}
