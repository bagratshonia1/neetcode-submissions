class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        result = helper(n, "", 0, 0);
        return result;
        
    }
    
    vector<string> helper(int n, string current, int open, int closed){
        vector<string> result;
        if(current.length() == 2 * n){
            result.push_back(current);
            return result;
        }
        if(open < n){
            vector<string> openbrackets = helper(n, current + "(", open + 1, closed);
            result.insert(result.end(), openbrackets.begin(), openbrackets.end());
        }
        if(closed < open){
            vector<string> closedbrackets = helper(n, current + ")", open, closed + 1);
            result.insert(result.end(), closedbrackets.begin(), closedbrackets.end());
        }
        return result;
    }
    
};

