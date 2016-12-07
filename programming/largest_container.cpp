/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container.
*/

// eg: 1 6 3 2 4 8
// maximum diff in X axis
// large Y and minimum diff in Y 
class Solution {
private:
    int max = -1;
public:
    int maxArea(vector<int>& height) {
        _maxArea(height, 0, height.size()-1);
        return max
    }
    int _maxArea(vector<int>& height, int i, int j) {
        if ( i >= j ) {
            return -1;
        }
        int area = (j - i) * std::min(height[i], height[j]);
        if ( area > max ) {
            max = area;
        }
    }
};)