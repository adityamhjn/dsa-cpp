/*
 * Problem: 53. Maximum Subarray (Kadane's Algorithm)
 * * Time Complexity: O(N) - We iterate through the array exactly once.
 * Space Complexity: O(1) - We only use two integer variables.
 * * Intuition: 
 * We maintain a running 'currentSum' of the contiguous subarray.
 * If 'currentSum' ever becomes negative, it is a liability to future elements,
 * so we reset it to 0. We continuously update 'maxSum' with the highest
 * 'currentSum' seen so far.
 */

#include <vector>
#include <algorithm> // Required for std::max

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // Initialize max_sum to the first element to handle arrays with all negative numbers
        int maxSum = nums[0]; 
        int currentSum = 0;
        
        for (int num : nums) {
            // If our running sum is negative, drop it entirely
            if (currentSum < 0) {
                currentSum = 0;
            }
            
            // Add the current number to the running sum
            currentSum += num;
            
            // Update the global maximum sum
            maxSum = std::max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};