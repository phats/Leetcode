class Solution {
public:
    unordered_set<int> myset;
    bool containsDuplicate(vector<int>& nums) {
        for (int i=0;i<nums.size();i++){
            auto got=myset.find(nums[i]);
            if (got==myset.end()){
                myset.insert(nums[i]);
            }
            else{
                return true;
            }
        }
        return false;
    }
};