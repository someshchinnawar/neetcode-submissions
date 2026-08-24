class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
            sort(stones.begin(),stones.end());

            int x = stones.back(); // get largest element
            stones.pop_back(); //poping the largets element

            int y = stones.back();
            stones.pop_back();

            //if stones are not equal
            if(x != y){
                stones.push_back(x-y);
            }
        }
        if(stones.empty()){
            return 0;
        }
        return stones[0];
    }
};
