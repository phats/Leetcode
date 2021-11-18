class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        int pos=-1;
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            cout<<" "<<mid;
            if (nums[mid]==target){
                pos=mid;
                break;
            }
            else if (nums[mid]<target) {
                left=mid+1;
            }
            else {
                right=mid-1;
            } 
        }
        if (pos != -1){
            left=pos;
            right=pos;
            while(left>=0 &&nums[left]==target){
                --left;
            }
            while(right <=(nums.size()-1) && nums[right]==target){
                ++right;
            }
            if (left<right) {
                res[0]=left+1;
                res[1]=right-1;
            }
            else {
                res[0]=res[1]=pos;
            }
        }
        return res;
    }
};