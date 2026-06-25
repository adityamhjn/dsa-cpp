class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int l=0, r=height.size()-1;
        int max_left= height[l], max_right= height[r];
        int total_water=0;
        while(l<r){
            if(max_left < max_right){
                l++;
                max_left= max(height[l], max_left);
                int trapped_water= max_left- height[l];
                total_water+=trapped_water;
            }
             else{
                r--;
                max_right= max(height[r], max_right);
                int trapped_water= max_right- height[r];
                total_water+=trapped_water;
            }
        }
        return total_water;
    }
};
