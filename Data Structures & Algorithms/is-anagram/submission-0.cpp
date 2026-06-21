class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq;
        if(s.length()!=t.length()) return false;
        for(int i=0; i<s.length();i++){
                freq[s[i]]++;
                freq[t[i]]--;
        }
        for(auto pair: freq){
                if(pair.second!=0)
                return false;
        }
        return true;
        }
};
