#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }
        
        int left = 0, right = n - 1;
        int maxArea = 0;
        int leftIndex = 0, rightIndex = 0;
        
        while (left < right) {
            int area = min(heights[left], heights[right]) * (right - left);
            if (area > maxArea) {
                maxArea = area;
                leftIndex = left;
                rightIndex = right;
            }
            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }
        
        cout << leftIndex << " " << rightIndex << endl;
    }
    return 0;
}
