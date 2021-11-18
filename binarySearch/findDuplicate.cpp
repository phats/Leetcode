class Solution {
public:
    
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for (int i=0;i<nums.size();i++){
            if (++(hashMap[nums[i]])==2){
                return nums[i];
            }
        }
        return -1;
    }
};