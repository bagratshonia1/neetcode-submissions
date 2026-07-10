class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int n = heights.size();
        int maximum = 0;
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[i] < heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                int w;
                if(s.empty()){
                    w = i;
                }else{
                    w = i - s.top() - 1;
                }
                maximum = max(maximum, h * w); 
            }
            s.push(i);
        }
        return maximum;

    }
};
