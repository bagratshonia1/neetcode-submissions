class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int left = 0;
        int right = s1.size() - 1;
        vector<int> firstWord (26, 0);
        vector<int> secondWord (26, 0);
        for(int i = 0; i < s1.size(); i++){
            firstWord[s1[i] - 'a']++;
            secondWord[s2[i] - 'a']++;
        }
        while(right < s2.size()){
            if(firstWord == secondWord){
                return true;
            }else{
                right++;
                //check once again because, after the increase by one
                //it may go out of bounds
                if(right < s2.size()) secondWord[s2[right] - 'a']++;
                secondWord[s2[left] - 'a']--;
                left++;
            }
        }
        return false;
    }
};
