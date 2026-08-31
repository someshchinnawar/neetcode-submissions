class Solution {
public:
    //brute
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>> newV;
        for(auto it : mp){
            newV.push_back({it.second,it.first});
        }
        sort(newV.rbegin(),newV.rend());

        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(newV[i].second);
        }

        return res;
    }

};
