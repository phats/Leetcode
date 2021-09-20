class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k==0 || nums.size()==0|| nums.size()==1) return;
        if (nums.size()>k){
        vector<int> vec1(nums.end()-k,nums.end());
        vector<int> vec2(nums.begin(),nums.end()-k);
        nums.erase(nums.begin(),nums.end());
        nums.insert(nums.begin(),vec2.begin(),vec2.end());
        nums.insert(nums.begin(),vec1.begin(),vec1.end());
        }
        else{
            rotate(nums,k-1);
            int tam=nums[nums.size()-1];
            nums.pop_back();
            nums.insert(nums.begin(),tam);
        }
    }
};