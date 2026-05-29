/*
 * Problem: 167. Two Sum II - Input Array Is Sorted
 * * Time Complexity: O(N) - We iterate through the array at most once.
 * Space Complexity: O(1) - We only use two pointers, requiring no extra memory.
 * * Intuition: 
 * Since the array is already sorted, we can use the Two-Pointer technique.
 * We place one pointer at the beginning (smallest value) and one at the end (largest value).
 * - If the sum is too large, we move the right pointer left to decrease the sum.
 * - If the sum is too small, we move the left pointer right to increase the sum.
 * - We are guaranteed exactly one solution.
 */

#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int currentSum = numbers[left] + numbers[right];
            
            if (currentSum > target) {
                right--; // Sum is too big, decrease it
            } 
            else if (currentSum < target) {
                left++;  // Sum is too small, increase it
            } 
            else {
                // Problem requires 1-indexed array, so we add 1 to our 0-indexed variables
                return {left + 1, right + 1};
            }
        }
        
        return {}; // Fallback, though the problem guarantees a solution
    }
};