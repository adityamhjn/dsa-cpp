class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            if (nums[i] > 0) break;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int target= -nums[i];
            int l = i+1;
            int r = nums.size()-1;

            while(l<r){
                int curr_sum= nums[l]+ nums[r];
                if(curr_sum == target){
                    result.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    l++;
                    r--;
                }
                else if( curr_sum > target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return result;
    }
};
