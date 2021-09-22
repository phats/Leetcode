class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int dem=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==0) {
                dem++;
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        for (int i=0;i<dem;i++){
            nums.push_back(0);
        }
    }
};