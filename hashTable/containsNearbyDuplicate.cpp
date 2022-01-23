class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;
        //first: nums[i] | second: newest index
        for (int i=0;i<nums.size();i++){
            auto got=myMap.find(nums[i]);
            if (got !=myMap.end()){
                if (i-got->second<=k){
                    return true;
                }
                got->second=i;
            }
            else{
                myMap.insert({nums[i],i});
            }
        }
        return false;
    }
};