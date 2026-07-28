class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int index){
        if(current.size() == nums.size()){
            return;
        }
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i - 1]){
                continue;
            }
            current.push_back(nums[i]);
            result.push_back(current);
            helper(nums, result, current, i + 1);
            current.pop_back();
        }
    }
  


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = 0;
        vector<int> current;
        vector<vector<int>> result;
        result.push_back({});
        helper(nums, result, current, index);
        return result;
    }
};