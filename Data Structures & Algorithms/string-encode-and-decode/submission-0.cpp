class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(string str: strs){
            encoded_string+=to_string(str.length())+"#"+str;
            
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i =0;
        while(i<s.size()){
            int j=s.find("#",i);
            int length= stoi(s.substr(i,j-i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }
        return result;
    }
};
