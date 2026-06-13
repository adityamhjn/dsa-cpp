/*
 * Problem: 410. Split Array Largest Sum (Binary Search on Answer)
 * * Time Complexity: O(N * log(S - M)) 
 * Where N is the number of elements, S is the sum of all elements, 
 * and M is the maximum single element.
 * Space Complexity: O(1) - No extra memory is allocated.
 * * Intuition: 
 * We are not searching for an index; we are binary searching for the optimal CAPACITY.
 * - The absolute minimum capacity (left) is the largest single element in the array.
 * - The absolute maximum capacity (right) is the sum of all elements.
 * For any given 'mid' capacity, we greedily simulate splitting the array. 
 * If we need more than 'k' splits, our capacity is too small (left = mid + 1).
 * If we can do it in 'k' or fewer splits, it's a valid candidate, but we try 
 * to find an even smaller valid capacity (right = mid - 1).
 */

#include <vector>
#include <algorithm> // Required for std::max

class Solution {
private:
    // Helper function to simulate if a given max capacity is possible with <= k splits
    bool canSplit(const std::vector<int>& nums, int k, int maxCapacity) {
        int splitsRequired = 1;
        int currentSubarraySum = 0;
        
        for (int num : nums) {
            if (currentSubarraySum + num <= maxCapacity) {
                // Add to current subarray
                currentSubarraySum += num;
            } else {
                // Close current subarray, start a new one
                splitsRequired++;
                currentSubarraySum = num;
            }
        }
        
        return splitsRequired <= k;
    }

public:
    int splitArray(std::vector<int>& nums, int k) {
        // Defensive check: Cannot split if k > number of elements
        if (nums.size() < k) return -1;
        
        int left = 0;
        int right = 0;
        
        // Optimize search boundaries:
        // Left bound = maximum single element
        // Right bound = sum of all elements
        for (int num : nums) {
            left = std::max(left, num);
            right += num;
        }
        
        int optimalCapacity = -1;
        
        // Standard Binary Search on the Capacity range
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canSplit(nums, k, mid)) {
                optimalCapacity = mid;  // Record valid candidate
                right = mid - 1;        // Attempt to find a smaller valid capacity
            } else {
                left = mid + 1;         // Capacity is too small, we need more room
            }
        }
        
        return optimalCapacity;
    }
};