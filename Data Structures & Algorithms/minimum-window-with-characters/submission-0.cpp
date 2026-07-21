class Solution {
public:
    //checks if map_1 contains everything from map_2
    bool isSubMap(unordered_map<char, int>& processed,
     unordered_map<char, int>& tMap){
        for(const auto& [key, value] : tMap){
            auto it = processed.find(key);
            if(it == processed.end() || it->second < value) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        unordered_map<char, int> processed;
        string result = "";
        for(int i = 0; i < t.length(); i++){
            tMap[t[i]]++;
        }
        int minLength = INT_MAX;
        int start = 0;
        int left = 0;
        int right = 0;
        while(right < s.length()){
            if(!isSubMap(processed, tMap)){
                processed[s[right]]++;
                result += s[right];
            }
            while(isSubMap(processed, tMap)){
                if(right - left + 1 < minLength){
                    minLength = right - left + 1;
                    start = left;
                }
                processed[s[left]]--;
                left++;
                result = result.substr(1, result.length() - 1);
            }
            right++;
        }
        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};
