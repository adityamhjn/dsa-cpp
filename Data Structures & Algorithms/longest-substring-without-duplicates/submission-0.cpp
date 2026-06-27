class Solution {
public:
    int lengthOfLongestSubstring(const string& s) { // CONST REFERENCE
        vector<bool> window(128, false); // O(1) space, instant lookups, no hashing
        int l = 0;
        int max_length = 0;
        
        for (int r = 0; r < s.length(); r++) {
            // If the character is already in the window, shrink from left
            while (window[s[r]]) {
                window[s[l]] = false;
                l++;
            }
            
            // Add the new character to the window
            window[s[r]] = true;
            max_length = max(max_length, r - l + 1);
        }
        
        return max_length;
    }
};