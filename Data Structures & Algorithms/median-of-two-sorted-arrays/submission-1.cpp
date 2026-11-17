class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        vector<int> a; //short
        vector<int> b; //long
        if(nums1.size() <= nums2.size()){
            a = nums1;
            b = nums2;
        }else{
            a = nums2;
            b = nums1;
        }
        int n = a.size();
        int m = b.size();
        int full = m + n;
        int half = full / 2;
        int left = -1;
        int right = n - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            int rest = half - mid - 2;
            int aLeft = (mid >= 0) ? a[mid] : INT_MIN ;
            int aRight = (mid + 1 < n) ? a[mid + 1] : INT_MAX;
            int bLeft = (rest >= 0) ? b[rest] : INT_MIN;
            int bRight = (rest + 1 < m) ? b[rest + 1] : INT_MAX;
            if(aLeft <= bRight && bLeft <= aRight){
                if(full % 2 == 0){
                    return ((double)max(aLeft, bLeft) + 
                    (double)min(aRight, bRight)) / 2.0;
                }else{
                    return (double)min(aRight, bRight);
                }
            }else if(aLeft > bRight){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return 0.0;
    }
};
