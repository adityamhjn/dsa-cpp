/*
 * Problem: 33. Search in Rotated Sorted Array
 * * Time Complexity: O(\log N) - We halve the search space on every iteration.
 * Space Complexity: O(1) - No extra memory is allocated.
 * * Intuition: 
 * Even though the array is rotated, dividing it in half guarantees that 
 * AT LEAST one half is strictly sorted. 
 * We first identify which half (left or right) is perfectly sorted. 
 * Then, we check if our target mathematically falls within that sorted range. 
 * If it does, we discard the other half. If not, we discard the sorted half.
 */

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // Prevent integer overflow when calculating mid
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check if the LEFT half is strictly sorted
            if (nums[left] <= nums[mid]) {
                // Check if the target falls within this strictly sorted left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Target is here, discard right half
                } else {
                    left = mid + 1;  // Target is not here, discard left half
                }
            } 
            // Otherwise, the RIGHT half MUST be strictly sorted
            else {
                // Check if the target falls within this strictly sorted right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Target is here, discard left half
                } else {
                    right = mid - 1; // Target is not here, discard right half
                }
            }
        }
        
        // Target was not found in the array
        return -1;
    }
};