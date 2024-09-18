// leetcode -> 42
class Solution {
public:
    int Area(vector<int>& height, int left[], int right[], int n) {
        int area = 0;
        for (int i = 0; i < n; i++) {
            int mini = min(left[i], (right[i]));
            int val = mini - height[i];
            area = area + val;
        }
        return area;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n];
        int right[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            if (left[i - 1] < height[i]) {
                left[i] = height[i];
            } else {
                left[i] = left[i - 1];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (right[i + 1] < height[i]) {
                right[i] = height[i];
            } else {
                right[i] = right[i + 1];
            }
        }
        int ans = Area(height, left, right, n);
        return ans;
    }
};
