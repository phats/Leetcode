class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        bool isRotated=0;
        if (nums[nums.size()-1]<nums[0]){
            isRotated=1;
        }
        if (isRotated && nums.size()>2){
            while(left<=right){
                int mid=max((left+right)/2,1);
                cout<<mid;
                if (nums[mid]<nums[mid-1]){
                    return nums[mid];
                }
                else if (nums[mid]>nums[0]){
                    left=mid+1;
                }
                else {
                    right=mid-1;
                }
            }
        }
        return nums[isRotated];
    }
};