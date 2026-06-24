class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int longest_streak = 0;
        
        for (int num : seen) { 
            if (!seen.count(num - 1)) {
                int current_num = num;
                int current_streak = 1;
                
                while (seen.count(current_num + 1)) {
                    current_num++;
                    current_streak++;
                }
                
                longest_streak = max(longest_streak, current_streak);
            }
        }
        return longest_streak;
    }
};