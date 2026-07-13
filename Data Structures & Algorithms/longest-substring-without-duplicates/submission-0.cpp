class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int result = 0;
        unordered_set<char> used;
        for(int right = 0; right < s.length(); right++){
            while(used.count(s[right])){
                used.erase(s[left]);
                left++;
            }
            used.insert(s[right]);
            result = max(result, right - left + 1);
        }
        return result;
    }
};
