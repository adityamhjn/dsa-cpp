/*
 * Problem: 852. Peak Index in a Mountain Array
 * * Time Complexity: O(log N) - We halve the search space on every iteration.
 * Space Complexity: O(1) - No extra memory is allocated.
 * * Intuition: 
 * We use Binary Search to find the exact inflection point. 
 * By restricting our search space to [1, n-2], we safely check neighbors without 
 * going out of bounds. 
 * - If mid is greater than both its neighbors, we found the peak.
 * - If mid is greater than its left neighbor but less than its right, we are 
 * climbing up. The peak is to the right.
 * - Otherwise, we are falling down. The peak is to the left.
 */

#include <vector>

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
        // Restrict search space to avoid out-of-bounds errors when checking neighbors
        int left = 1;
        int right = arr.size() - 2;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Condition 1: We are at the absolute peak
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } 
            // Condition 2: We are on the upward slope
            else if (arr[mid - 1] < arr[mid]) {
                left = mid + 1;
            } 
            // Condition 3: We are on the downward slope
            else {
                right = mid - 1;
            }
        }
        
        return -1; // Fallback, though the problem guarantees a peak exists
    }
};