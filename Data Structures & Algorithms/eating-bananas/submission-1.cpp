class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end(), [](int a, int b){
            return a > b;
        });
        int left = 1;
        int right = piles[0];
        int result = INT_MAX;
        while(left <= right){ //you have to check equal indexes as well
            int currentK = (right + left) / 2;
            long long currentTime = 0; // it is better to be a long long
            //because piles[i] <= 10^9 piles.length <= 10^4 and currentTime
            //can reach up to 10^9 * 10^4 = 10^13
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
