class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        vector<int> prefix;
        vector<int> sufix;
        int suf = 1;
        int pre = 1;
        for(int i = 0; i < nums.size(); i++){
            if (i == 0){
                prefix.push_back(1);
            }else{
                pre *= nums[i-1];
                prefix.push_back(pre);   
            }
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                sufix.push_back(1);
            }else{
                suf *= nums[i + 1];
                sufix.push_back(suf);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            output.push_back(sufix[nums.size() - 1 - i] * prefix[i]);
        }
        return output;
    }
};
