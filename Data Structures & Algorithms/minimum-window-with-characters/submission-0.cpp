class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";
        vector<int> target_count(128,0);
        int need=0;
        for (char c : t) {
            if (target_count[c] == 0) need++; 
            target_count[c]++;
        }
        vector<int> window_count(128, 0);
        int have = 0;
        
        int min_len = 1e9;
        int start_idx = -1;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            window_count[c]++;
            if (target_count[c] > 0 && window_count[c] == target_count[c]) have++;

            while(have == need){
                if(right-left+1< min_len){
                    min_len = right-left+1;
                    start_idx= left;
                }

                char left_char = s[left];

                window_count[left_char]--;

                if(target_count[left_char] > 0 && window_count[left_char]< target_count[left_char]){
                    have--;
                }
                left++;
            }
        }
        return min_len == 1e9 ? "" : s.substr(start_idx, min_len);
    }
};
