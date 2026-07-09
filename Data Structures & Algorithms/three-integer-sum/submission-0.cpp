class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<int> sorted = nums;
        vector<vector<int> > result;
        sort(sorted.begin(), sorted.end());
        int left = 0;
        int right = 0;
        for(int i = 0; i < sorted.size() - 2; i++){
            if(i > 0 && sorted[i] == sorted[i - 1]) continue;
            left = i + 1;
            right = sorted.size() - 1;
            int target = -sorted[i];
            while(left < right){
                if(sorted[left] + sorted[right] < target){
                    left++;
                }
                else if(sorted[left] + sorted[right] > target){
                    right--;
                }
                else if(sorted[left] + sorted[right] == target){
                    result.push_back({sorted[i], sorted[left], sorted[right]});
                    left++;
                    right--;
                    //what if we move left and right inward and the duplicate
                    //triplet occurs
                    while(left < right && sorted[left] == sorted[left - 1]) left++;
                    while(left < right && sorted[right] == sorted[right + 1]) right--;
                }
            }
        }
        return result;
    }
};