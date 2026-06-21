class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num:nums){
            seen.count(num);
            if(seen.count(num)==1)
            return true;
            else
            seen.insert(num);
            }
            return false;
        }
        
    };
        