/*
 * Problem: 11. Container With Most Water
 * * Time Complexity: O(N) - We scan the array exactly once.
 * Space Complexity: O(1) - We only allocate memory for a few tracking integers.
 * * Intuition: 
 * The total volume of water is bottlenecked by the shorter line. 
 * We maximize the initial width by placing pointers at both extremes.
 * After calculating the current area, we MUST move the pointer at the shorter 
 * line inward. Moving the taller line is mathematically guaranteed to either 
 * shrink or maintain the current area, never increase it.
 */

#include <vector>
#include <algorithm> // Required for std::min and std::max

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Calculate dimensions
            int currentWidth = right - left;
            int currentHeight = std::min(height[left], height[right]);
            
            // Update global maximum
            int currentWater = currentWidth * currentHeight;
            maxWater = std::max(maxWater, currentWater);
            
            // The bottleneck principle: abandon the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};