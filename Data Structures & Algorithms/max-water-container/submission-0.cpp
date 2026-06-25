class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int max_area = 0;
        while (l < r) {
            int curr_area= (r-l)*min(heights[l], heights[r]);
            max_area= max(curr_area, max_area);
                if(heights[l] < heights[r]){
                    l++;
                }
                else
                r--;
        }

        return max_area;
    }
};
