/*
 * Problem: 136. Single Number
 * * Time Complexity: O(N) - We iterate through the array exactly once.
 * Space Complexity: O(1) - No extra memory is used (in-place computation).
 * * Intuition: 
 * We use the XOR bitwise operator (^). 
 * 1. XORing a number with itself results in 0 (n ^ n = 0).
 * 2. XORing a number with 0 results in the number itself (n ^ 0 = n).
 * By XORing all elements in the array, all duplicate pairs cancel out to 0, 
 * leaving only the single unique number.
 */

#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        
        // Range-based for loop (C++ specific feature)
        for (int num : nums) {
            result ^= num;
        }
        
        return result;
    }
};