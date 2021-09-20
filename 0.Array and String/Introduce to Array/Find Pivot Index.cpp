class Solution {
public:
    int sum_in_i(int i, vector<int>& nums) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum = sum + nums[j];
        }
        return sum;
    }
    int pivotIndex(vector<int>& nums) {
        int sum_nums = sum_in_i(nums.size(), nums);
        for (int i = 0; i < nums.size(); i++) {
            if (sum_in_i(i, nums) == sum_nums - sum_in_i(i, nums) - nums[i])
                return i;
        }
        return -1;
    }
};