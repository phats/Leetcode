class Solution {
public:
    void swap(int& a,int& b){
        int temp=a;
        a=b;
        b=temp;
    }
    int removeElement(vector<int>& nums, int val) {
        int count =0;
        int i=0,j=nums.size()-1;
        
        while(i<=j){
            if (nums[j]==val){
                --j;
                ++count;
                continue;
            }
            else if (nums[i]==val) {
                swap(nums[i],nums[j]);
                --j;
                ++count;
            }
            ++i;
        }
        if (count){
            nums.erase(nums.end()-count,nums.end());
        }
        return nums.size();
    }
};