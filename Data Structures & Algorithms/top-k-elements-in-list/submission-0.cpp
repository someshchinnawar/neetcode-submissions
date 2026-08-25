class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(auto it: mp){
            minHeap.push({it.second,it.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int>res;
        while(k > 0){
            res.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }
        return res;
    }

};
