class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& result, vector<bool>& used, vector<int>& current){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                current.push_back(nums[i]);
                used[i] = true;
                helper(nums, result, used, current);
                current.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used;
        vector<int> current;
        for(int i = 0; i < nums.size(); i++){
            used.push_back(false);
        }
        helper(nums, result, used, current);
        return result;
    }
};