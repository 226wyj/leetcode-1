#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int test[] = {1,1,1,1,0,1,0,1,1,0,0,0,}; // red: 1, green: 0
  // find the longest range where # of 1 - # of 0 is the
  int prevMax = test [0];
  int start = 0, end = 0, count = 0;
  for (int i = 1; i < (int) (sizeof (test) / sizeof (int)); ++i)
   {
      int currMax = 0;
      if (test [i] == 0) // green
        {
          currMax = max (prevMax - 1, -1);
          if (currMax == -1)
            start = i;
          prevMax = currMax;
        }
      else // red
        {
          currMax = max (prevMax + 1, 1);
          if (currMax == 1)
            start = i;
          prevMax = currMax;
        }
      if (currMax > count)
        {
          count = currMax;
          end = i;
        }
    }
  printf ("start: %d, end: %d\n", start, end);
  return 0;
}
