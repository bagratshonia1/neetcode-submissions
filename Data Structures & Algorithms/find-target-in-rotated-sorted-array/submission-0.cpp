class Solution {
public:
    int binary(int left, int right, vector<int>& nums, int& target){
        if(left > right) return -1;
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            return mid;
        }else 
        if(nums[mid] < target){
            return binary(mid + 1, right, nums, target);
        }else{
            return binary(left, mid - 1, nums, target);
        }
    }

    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; 
        int result = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            //left part is sorted
            if(nums[left] <= nums[mid]){
                //so the target is in the sorted area
                if(target >= nums[left] && target <= nums[mid]){
                    result = binary(left, mid, nums, target);
                    break;
                }else{
                    left = mid + 1;
                }
            }else{
                //so the target is in the right sorted area
                if(target >= nums[mid] && target <= nums[right]){
                    result = binary(mid, right, nums, target);
                    break;
                }else{
                    right = mid - 1;
                }
            }
        }
        return result;

    }
};
