class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        // O(1) Space: A fixed array for 26 lowercase letters
        vector<int> freq(26, 0); 
        
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++; // Increment for string s
            freq[t[i] - 'a']--; // Decrement for string t
        }
        
        // Range-based loop with reference to avoid copying
        for (const int& count : freq) {
            if (count != 0) return false;
        }
        
        return true;
    }
};