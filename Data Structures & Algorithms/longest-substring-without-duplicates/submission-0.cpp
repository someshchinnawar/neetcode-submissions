class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l  = 0; 
        int r = 0;
        int maxlen = 0;
        unordered_map<char,int> mp;
        while(r < s.length()){
            if(mp.find(s[r]) != mp.end()){
                if(mp[s[r]] >= l){
                    l = mp[s[r]] + 1;
                }
            }
            mp[s[r]] = r;
            int len = r - l + 1;
            maxlen = max(len,maxlen);
            r++;
        }
        return maxlen;
    }
};
