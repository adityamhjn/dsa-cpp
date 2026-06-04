/*
 * Problem: 540. Single Element in a Sorted Array
 * Time Complexity: O(log N) - Binary Search eliminates half the array each step.
 * Space Complexity: O(1) - Constant auxiliary space.
 * * Intuition: 
 * Elements appear in pairs. Normal pairs start at an EVEN index and end at an ODD index (e.g., 0 and 1, 2 and 3).
 * The unique single element disrupts this pattern.
 * - Before the unique element: First copy is at an EVEN index, second copy is at an ODD index.
 * - After the unique element: First copy is at an ODD index, second copy is at an EVEN index.
 * * We check if 'mid' matches its twin. Based on whether 'mid' is odd or even, we can determine 
 * if we are standing before or after the disruption point.
 */

#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int n = nums.size();
        
        // Base Case: Only one element exists
        if (n == 1) return nums[0];
        
        // Defensive Audits: Check boundaries upfront to protect loop indices
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        
        // Safe internal search space [1, n-2]
        int left = 1;
        int right = n - 2;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If mid is not equal to its left or right neighbor, it is the single element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            
            // Binary Search Index Parity Logic
            // Case A: mid is an EVEN index
            if (mid % 2 == 0) {
                // Normal pair sequence intact to the left. Disruption is ahead.
                if (nums[mid] == nums[mid + 1]) {
                    left = mid + 1;
                } else { // Pair started early; disruption is behind.
                    right = mid - 1;
                }
            } 
            // Case B: mid is an ODD index
            else {
                // Normal pair sequence intact to the left. Disruption is ahead.
                if (nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                } else { // Pair shifted; disruption is behind.
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};