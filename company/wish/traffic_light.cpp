#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // int test[] = {1,1,1,1,0,1,0,1,1,0,0,0,}; // red: 1, green: -1
    int test[] = { -1, 1, 1, -1, 1, 1 }; // 1 , 2
    // find the longest range where # of 1 - # of 0
    // in the range the smaller the # of 0s the better
    int prevMax = test[0];
    int currStart = 0, end = 0, count = 0;
    int start = 0;
    for (int i = 1; i < (int)(sizeof(test) / sizeof(int)); ++i) {
        int currMax = max(test[i], prevMax + test[i]);
        if (currMax == test[i])
            currStart = i;
        prevMax = currMax;
        if (currMax > count) {
            count = currMax;
            start = currStart;
            end = i;
        }
    }
    printf("start: %d, end: %d\n", start, end);
    return 0;
}
