class TimeMap {
public:
    unordered_map<string, vector<pair<int, string> > > m;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(timestamp, value));
    }
    
    //the timestamps are set in ascending order, so the
    //vector is sorted by default
    string get(string key, int timestamp) {
        string result = "";
        vector<pair<int, string> >& v = m[key]; //use reference so it does not copy
        int left = 0;                           //the whole vector every single time
        int right = v.size() - 1;
        while (left <= right){
            int mid = (left + right) / 2;
            if(v[mid].first <= timestamp){
                result = v[mid].second;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return result;
    }
};
