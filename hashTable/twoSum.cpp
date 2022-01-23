class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap;
        for (int i=0;i<nums.size();i++){
            myMap.insert({nums[i],i});
        }
        vector<int> res;
        for (int i=0;i<nums.size();i++){
            int needFind=target-nums[i];
            auto got=myMap.find(needFind);
            if (got!=myMap.end() && got->second != i){
                res.push_back(i);
                res.push_back(got->second);
                return res;
            }
        }
        return res;
    }
};