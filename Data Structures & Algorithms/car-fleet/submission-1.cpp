class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector <pair <int, int> > posNSpeed;
        stack<pair <int, int> > stk;

        for(int i = 0; i < speed.size(); i++){
            posNSpeed.push_back(make_pair(position[i], speed[i]));
        }
        sort(posNSpeed.begin(), posNSpeed.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first > b.first;
        });
        for(int i = 0; i < posNSpeed.size(); i++){
            if(stk.empty()){
              stk.push(posNSpeed[i]);
              continue;
            }
            int s1 = target - stk.top().first;
            int v1 = stk.top().second;
            int s2 = target - posNSpeed[i].first;
            int v2 = posNSpeed[i].second;
            double t1 = (double)s1 / v1;
            double t2 = (double)s2 / v2;
            if(t2 > t1){
                stk.push(posNSpeed[i]);
            }
        }
        return stk.size();
    }
};
