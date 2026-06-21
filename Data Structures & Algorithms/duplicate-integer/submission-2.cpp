class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        // High-Performance Tip: Prevent rehashing
        seen.reserve(nums.size()); 

        for (int num : nums) {
            if (seen.count(num)) {
                return true; 
            }
            seen.insert(num);
        }
        return false;
    }
};