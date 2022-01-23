class Solution {
public:
    unordered_set<int> myset;
    int singleNumber(vector<int>& nums) {
        for (int i=0;i<nums.size();i++){
            auto got=myset.find(nums[i]);
            if (got!=myset.end()){
                myset.erase(nums[i]);
            }
            else{
                myset.insert(nums[i]);
            }
        }
        for (int i=0;i<nums.size();i++){
            auto got=myset.find(nums[i]);
            if (got!=myset.end()){
                return nums[i];
            }
        }
        return -1;   
    }
};