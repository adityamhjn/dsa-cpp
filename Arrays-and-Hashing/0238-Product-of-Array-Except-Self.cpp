/*
 * Problem: 238. Product of Array Except Self
 * * Time Complexity: O(N) - We make two separate O(N) passes through the array.
 * Space Complexity: O(1) - Auxiliary space is O(1) because the output array does not count toward space complexity.
 * * Intuition: 
 * Since division is banned, we must calculate the product of all elements to the 
 * left of 'i', and multiply it by the product of all elements to the right of 'i'.
 * We do this in two passes: 
 * 1. Left-to-right pass calculates all prefix products and stores them in 'answer'.
 * 2. Right-to-left pass calculates the suffix product on the fly and multiplies it into 'answer'.
 */

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1);
        
        // Pass 1: Calculate prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        
        // Pass 2: Calculate suffix products and multiply with prefixes
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        
        return answer;
    }
};