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