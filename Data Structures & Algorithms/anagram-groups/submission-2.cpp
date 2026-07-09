class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string> > frequency;
        for(int i = 0; i < strs.size(); i++){
            vector<int> current (26, 0);
            for(char c : strs[i]){
                current[c - 'a']++;
            }
            if(frequency.count(current)){
                frequency[current].push_back(strs[i]);
            }else{
                vector<string> strings;
                strings.push_back(strs[i]);
                frequency[current] = strings;
            }
        }
        vector<vector<string> > result;
        for(auto&[key, val] : frequency){
            result.push_back(frequency[key]);
        }
        return result;
    }
};
