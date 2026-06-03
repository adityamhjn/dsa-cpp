/*
 * Problem: 217. Contains Duplicate
 * * Time Complexity: O(N) - We scan the array exactly once.
 * Space Complexity: O(N) - In the worst case, the set stores every unique number.
 * * Intuition: 
 * We use a Hash Set to track numbers we have already seen.
 * As we iterate, if the current number is already in the set, we found a duplicate.
 * If not, we add it to the set and continue. 
 * This reduces the time complexity from O(N^2) to O(N).
 */
#include <iostream>
#include <vector>
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num) == 1) {
                return true; // Direct execution. No 'check' variable needed.
            }
            seen.insert(num);
        }
        return false; // If we survive the loop, it's false.
    }
};