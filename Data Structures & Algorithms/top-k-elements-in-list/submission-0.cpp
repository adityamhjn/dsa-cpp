class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }  
        vector<vector<int>> buckets(nums.size()+1);
        vector<int> result;

        for (auto pair : freq) {
        int current_number = pair.first;
        int current_count = pair.second;
        buckets[current_count].push_back(current_number);
        }
        for(int i =buckets.size()-1; i>=0; i--){
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                return result;
                }
        }
        }
        return result;
    }
    
};
