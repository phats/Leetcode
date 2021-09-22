class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> temp;
        vector<int> result;
        for (int i=0;i<nums.size();i++){
            temp.push_back(i+1);
        }
        for (int i=0;i<nums.size();i++){
            if (nums[i] == temp[nums[i]-1]){
                temp[nums[i]-1]=0;
            }
        }
        for (int i=0;i<temp.size();i++){
            if (temp[i] != 0) result.push_back(temp[i]);
        }
        return result;
    }
};