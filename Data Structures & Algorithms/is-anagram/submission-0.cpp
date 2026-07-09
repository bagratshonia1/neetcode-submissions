class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for(int i = 0; i < s.length(); i++){
            if(s_map.contains(s[i])){
                s_map[s[i]]++;
            }
            s_map.insert({s[i], 1});
        }
        for(int i = 0; i < t.length(); i++){
            if(t_map.contains(t[i])){
                t_map[t[i]]++;
            }
            t_map.insert({t[i], 1});
        }
        return s_map == t_map;
    }
};
