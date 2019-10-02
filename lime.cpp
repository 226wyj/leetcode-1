#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h> // for INT_MIN
using namespace std;

// # (10,10, 30), (25,25, 20) T
// # (10,10, 30), (25,25, 20), (35,45, 10) F
// # (10,10, 30), (25,25‍‍‌‌‍‍‌‍‌‍‍‌‍‌‌‍‌‍, 20), (70,10, 15), (70,20, 15), (80,35, 20) F
// # (10,10, 30), (25,25, 20), (70,20, 15), (80,35, 20) T
int main () {
    int y_base = 0, y_top = 50;
    vector<vector<int>> circles = {{10, 10, 30}, {25, 25, 20}, {70, 20, 15}, {80, 35, 20}};

    sort(circles.begin(), circles.end());
    for (size_t i = 0; i < circles.size(); i++)
    {
        cout << circles[i][0] << " " << circles[i][1] << " " << circles[i][2] << endl;
    }
    
    bool res = true;
    // get min and max
    int min_y = circles[0][1] - circles[0][2], max_y = circles[0][1] + circles[0][2];
    for (int i = 1; i < circles.size(); i++)
    {
        bool conncected = false;
        // check if intersect with previous one
        int curr = circles[i][0] - circles[i][2];
        int prev = circles[i - 1][0] + circles[i - 1][2];
        if (curr <= prev)
            conncected = true;
        
        int curr_bottom_y = circles[i][1] - circles[i][2];
        int curr_top_y = circles[i][1] + circles[i][2];

        if (conncected) {
            min_y = min(min_y, curr_bottom_y);
            max_y = max(max_y, curr_top_y);
        } else {
            min_y = curr_bottom_y;
            max_y = curr_top_y;
        }

        if (min_y <= y_base && max_y >= y_top) {
            res = false;
            break;
        }
    }
    printf("y max: %d\ny min: %d\n", max_y, min_y);
    cout << res << endl;
    
    return 0;
}

