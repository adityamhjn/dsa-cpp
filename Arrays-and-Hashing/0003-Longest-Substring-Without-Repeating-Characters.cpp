/*
 * Problem: 3. Longest Substring Without Repeating Characters
 * * Time Complexity: O(N) - Each character is visited at most twice (once by right, once by left).
 * Space Complexity: O(1) - The Hash Set will store a maximum of 26 English letters (or 128 ASCII characters), which is constant space.
 * * Intuition: 
 * We use a Dynamic Sliding Window. 
 * The 'right' pointer expands the window by adding characters to our Hash Set.
 * If we encounter a duplicate, the window is invalid. The 'left' pointer acts as an 
 * exhaust valve, shrinking the window from behind and removing characters from the 
 * set until the duplicate is destroyed. 
 */

#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> seen;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            
            // The Exhaust Valve: Shrink the window if a duplicate is found
            while (seen.count(s[right]) == 1) {
                seen.erase(s[left]);
                left++;
            }
            
            // Add the new character to the valid window
            seen.insert(s[right]);
            
            // Calculate the current window size (End - Start + 1)
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};