class Solution {
public:
    bool exists(int left, int right, vector<int>& v, int& target){
        if(left > right) return false;
        int mid = left + (right - left) / 2;
        if(v[mid] == target) return true;
        else if(v[mid] < target){
            return exists(mid + 1, right, v, target);
        }else{
            return exists(left, mid - 1, v, target);
        }
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> v;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                v.push_back(matrix[i][j]);
            }
        }
        int l = 0;
        int r = v.size() - 1;
        return exists(l, r, v, target);

    }
};
