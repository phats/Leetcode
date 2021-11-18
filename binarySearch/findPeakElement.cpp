class Solution {
public:
    bool isPeak(vector<int> nums,int i){
        if (i==0){
            if (nums[0]>nums[1]){
                return 1;
            }
            else {
                return 0;
            }
        }
        else if (i==nums.size()-1){
            if (nums[i]>nums[i-1]){
                return 1;
            }
            else {
                return 0;
            }
        }
        else if (nums[i]>nums[i-1] && nums[i]>nums[i+1]){
            return 1;
        }
        else {
            return 0;
        }
    }
    int findPeakElement(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        if (nums.size()==2){
            if (isPeak(nums,0)) return 0;
            else return 1;
        }
        if (nums.size()==1){
            return 0;
        }
        while(left<=right){
            int mid=(left+right)/2;
            cout<<mid<<" ";
            if (isPeak(nums,mid)){
                return mid;
            }
            else if (nums[mid]>nums[mid+1]){
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return 0;
    }
};