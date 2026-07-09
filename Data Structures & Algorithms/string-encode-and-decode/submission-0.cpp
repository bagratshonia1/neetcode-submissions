class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for(int i = 0; i < strs.size(); i++){
            int size = strs[i].length();
            string strSize = to_string(size);
            encoded = encoded + strSize + '#' + strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i < s.length()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            int wordStart = j + 1;
            string word = s.substr(wordStart, len);
            result.push_back(word);
            i = wordStart + len;
        }
        return result;
    }
};
