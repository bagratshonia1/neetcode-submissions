class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pairs;
        for(int i = 0; i < nums.size(); i++){
            int target_2 = target - nums[i];
            if(pairs.count(target_2)){
                return {pairs[target_2], i};
            }   
            pairs[nums[i]] = i;
        }
        return {};
    }
};
