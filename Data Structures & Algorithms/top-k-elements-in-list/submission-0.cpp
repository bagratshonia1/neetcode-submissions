class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        vector<pair<int, int> > f;
        for(auto[key, value] : freq){
            pair<int, int> current = {key, value};
            f.push_back(current);
        }
        sort(f.begin(), f.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        });
        for(int i = 0; i < k; i++){
            result.push_back(f[i].first);
        }
        return result;
    }
};
