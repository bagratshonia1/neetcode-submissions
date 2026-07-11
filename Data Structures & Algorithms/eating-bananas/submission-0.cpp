class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end(), [](int a, int b){
            return a > b;
        });
        int left = 1;
        int right = piles[0];
        int result = INT_MAX;
        while(left <= right){
            int currentK = (right + left) / 2;
            int currentTime = 0;
            for(int i = 0; i < piles.size(); i++){
                double singleTime= ((double)piles[i] / currentK);
                currentTime += ceil(singleTime);
            }
            if(currentTime <= h){
                right = currentK - 1;
                result = min(result, currentK);
            }else{
                left = currentK + 1;
            }
        }
        return result;
    }
};
