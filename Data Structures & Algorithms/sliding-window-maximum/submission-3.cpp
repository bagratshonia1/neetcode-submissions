class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        pair<int, int> currMax = {INT_MIN, INT_MIN}; //value, index
        vector<int> result;
        int left = 0;
        int right = k - 1;
        for(int i = 0; i < k; i++){
            if(currMax.first < nums[i]){
                currMax.first = nums[i];
                currMax.second = i;
            }
        }
        while(right < nums.size()){
            if(currMax.second < left){
                currMax = {INT_MIN, INT_MIN};
                for(int i = left; i < left + k; i++){
                    if(currMax.first < nums[i]){
                    currMax.first = nums[i];
                    currMax.second = i;
                    }
                } 
            }
            if(nums[right] > currMax.first){
                currMax.first = nums[right];
                currMax.second = right;
            }
            result.push_back(currMax.first);
            left++;
            right++;
        }
        return result;
    }
};
