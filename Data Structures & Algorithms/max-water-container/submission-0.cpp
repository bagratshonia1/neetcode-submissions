class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size() - 1;
        int result = 0;
        while(start < end){
            int width = end - start;
            int height = min(heights[start], heights[end]);
            int currentArea = width * height;
            result = max(result, currentArea);
            if(heights[start] < heights[end]){
                start++;
            }else
            if(heights[start] > heights[end]){
                end--;
            }else
            if(heights[start] == heights[end]){
                start++;
                end--;
            }
        }
        return result;
    }
};
