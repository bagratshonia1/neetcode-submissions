class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> used;
        int result = 0;
        int l = 0;
        int maxFreq = 0;
        for(int r = 0; r < s.length(); r++){
            used[s[r]]++;
            maxFreq = max(maxFreq, used[s[r]]);
            while(r - l + 1 - maxFreq > k){
                used[s[l]]--;
                l++;
            }
            result = max(r - l + 1, result);
        }
        return result;
    }
};
