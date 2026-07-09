class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maximum = 1;
        unordered_set<int> hash(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            if(!hash.count(n - 1)){
                int temp = n;
                int curMax = 1;
                while(hash.count(temp + 1)){
                    temp++;
                    curMax++;
                }
                maximum = max(curMax, maximum);
            }
        }
        return maximum;
    }
};
