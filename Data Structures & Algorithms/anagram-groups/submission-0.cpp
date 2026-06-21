class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        
        // 1. Pass by CONST REFERENCE to prevent copying strings
        for (const string& s : strs) {
            vector<int> freq(26, 0);
            
            // Cleaner character iteration
            for (char c : s) {
                freq[c - 'a']++;
            }
            
            string key = "";
            for (int count : freq) {
                key += to_string(count) + "#";
            }
            
            group[key].push_back(s);
        }
        
        vector<vector<string>> result;
        result.reserve(group.size()); // 2. Prevent dynamic reallocation
        
        // 3. Pass by REFERENCE to prevent copying massive string vectors
        for (auto& pair : group) {
            result.push_back(std::move(pair.second)); // std::move transfers ownership instantly
        }

        return result;
    }
};