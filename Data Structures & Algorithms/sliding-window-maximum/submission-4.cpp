class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> mdq; //stores indices
        vector<int> result;
        int left = 0;
        int right = 0;
        while(right < nums.size())
        {
            //we pop smaller values from the deque so it is
            //monotonically decreasing queue
            while(!mdq.empty() && nums[mdq.back()] < nums[right]){
                mdq.pop_back();
            }
            mdq.push_back(right);
            //if the leftmost (maximum) element is no longer in the
            //window we pop it
            if(left > mdq[0]){
                mdq.pop_front();
            }
            //since we start both indexes at 0, we need to store maximums
            //after the window size becomes k, not before that
            //and only after storing do we update the left pointer, but
            //right is always updated
            if(right + 1 >= k){
                result.push_back(nums[mdq[0]]);
                left++;
            }
            right++;
        }
        return result;
    }
};
