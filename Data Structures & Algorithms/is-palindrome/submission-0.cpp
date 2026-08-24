class Solution {
public:
    bool isPalindrome(string s) {
        string r;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                r += tolower(s[i]);
            }
        }
        int i = 0;
        int j = r.length()-1;
        while(i < j){
            if(r[i] != r[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
