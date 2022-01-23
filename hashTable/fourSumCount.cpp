class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> myMap;
        int count=0;
        for (int i=0;i<nums1.size();i++){
            for (int j=0;j<nums2.size();j++){
                auto got=myMap.find(nums1[i]+nums2[j]);
                if (got!=myMap.end()){
                    ++got->second;
                }
                else{
                    myMap.insert({nums1[i]+nums2[j],1});
                }
            }
        }
        for (int i=0;i<nums3.size();i++){
            for (int j=0;j<nums4.size();j++){
                auto got=myMap.find(-(nums3[i]+nums4[j]));
                if (got!=myMap.end()){
                    count+=got->second;
                }
            }
        }
        return count;
    }
};