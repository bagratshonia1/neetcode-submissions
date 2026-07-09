class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        vector<int> maxLeft;
        vector<int> maxRight;
        int maxL = 0;
        int maxR = 0;
        maxLeft.push_back(0);
        for(int i = 1; i <= height.size(); i++){
            int potentialMax = height[i - 1];
            maxL = max(maxL, potentialMax);
            maxLeft.push_back(maxL);
        }
        //maxRight is reversed
        maxRight.push_back(0);
        for(int i = height.size() - 2; i >= -1; i--){
            int potentialMax = height[i + 1];
            maxR = max(maxR, potentialMax);
            maxRight.push_back(maxR);
        }

        int result = 0;
        for(int i = 0; i < height.size(); i++){
            int maxHeight = 
            min(maxLeft[i], maxRight[height.size() - 1 - i]);
            int trapped = maxHeight - height[i];
            if(trapped <= 0){
                result += 0;
            }else{
                result += trapped;
            }
            
        }
        return result;

    }
};
