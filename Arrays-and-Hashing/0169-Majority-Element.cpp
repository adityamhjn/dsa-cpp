/*
 * Problem: 169. Majority Element
 * * Time Complexity: O(N) - We iterate through the array exactly once.
 * Space Complexity: O(1) - We only maintain two integer variables (candidate and count).
 * * Intuition: 
 * We use the Boyer-Moore Voting Algorithm. 
 * We maintain a 'candidate' and a 'count'. 
 * If 'count' reaches 0, we assume the current number is the new candidate.
 * If the next number matches the candidate, we increment count. 
 * If it differs, we decrement. 
 * Since the majority element is guaranteed to appear more than n/2 times, 
 * its count will mathematically always be > 0 at the end of the traversal.
 */

#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // If our count drops to zero, the current number takes over as the candidate
            if (count == 0) {
                candidate = num;
            }
            
            // Reinforce the candidate, or weaken it if the current number is an enemy
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};