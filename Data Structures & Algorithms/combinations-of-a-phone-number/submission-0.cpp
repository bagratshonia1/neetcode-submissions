class Solution {
public:
  map<char, string> keyboard = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        result = helper(digits, "", 0);
        return result;
    }

    vector<string> helper(string digits, string current, int index){
        vector<string> result;
        if(digits == ""){
            return {};
        }
        if(current.length() == digits.length()){
            result.push_back(current);
            return result;
        }
        string temp = keyboard[digits[index]];
        if(current.length() < digits.length()){
            for(int i = 0; i < temp.length(); i++){
                vector<string> notFinalResult = helper(digits, current + temp[i], index + 1);
                result.insert(result.end(), notFinalResult.begin(), notFinalResult.end());
            }
        }
        return result;
    }
};