class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> anag(26, 0);
        int n = s.length();
        for(int i = 0; i < n; i++){
            char char_s = s[i];
            char char_t = t[i];
            anag[char_s - 'a']++;
            anag[char_t -'a']--;
        }
        for(int i = 0; i < anag.size(); i++){
            if(anag[i] != 0){
                return false;
            }
        }
        return true;
    }
};
