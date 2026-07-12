class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        //this condition will be satisfied only if the array is sorted.
        if(nums[left] < nums[right]) return nums[0];
        int result = INT_MAX;
        while(left <= right){
            int mid = (left + right) / 2;
            result = min(result, nums[mid]);
            if(nums[left] <= nums[mid]){
                result = min(result, nums[left]);
                left = mid + 1;
            }else{
                result = min(result, nums[mid]);
                right = mid - 1;
            }
        }
        return result;
    }
};
