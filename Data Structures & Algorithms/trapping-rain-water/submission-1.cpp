class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = height[left];
        int maxRight = height[right];
        int result = 0;
        while(left < right){
            int minimum = min(maxLeft, maxRight);
            int current;
            if(maxLeft <= maxRight){
                current = minimum - height[left];
                if(current <= 0){
                    result += 0;
                }
                else{
                    result += current;
                }
                left++;
                maxLeft = max(maxLeft, height[left]);
            }else{
                current = minimum - height[right];
                if(current <= 0){
                    result += 0;
                }else{
                    result += current;
                }
                right--;
                maxRight = max(maxRight, height[right]);
            }
        }
        return result;
    }
};
