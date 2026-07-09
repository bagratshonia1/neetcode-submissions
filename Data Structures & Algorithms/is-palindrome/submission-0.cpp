class Solution {
public:
    bool isAlphaNumeric(char c){
        if((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9')){
            return true;
        }else{
            return false;
        }
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            if(isAlphaNumeric(s[i]) && isAlphaNumeric(s[j])){
                if(tolower(s[i]) != tolower(s[j])){
                    return false;
                }else{
                    i++;
                    j--;
                }
            }else if(!isAlphaNumeric(s[i])){
                i++;
            }else if(!isAlphaNumeric(s[j])){
                j--;
            }
        }
        return true;
    }
};
