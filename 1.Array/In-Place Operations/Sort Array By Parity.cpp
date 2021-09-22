class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result(nums);
        int j=0;
        int tam;
        for (int i=0;i<result.size();i++){
            if (result[i] %2==0) {
                tam=result[j];
                result[j]=result[i];
                result[i]=tam;
                j++;
            }
        }
        return result;
    }
};