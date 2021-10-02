class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size()==1) 
            return 0;
        else {

            int firstMaximumNumber=INT_MIN;
            int indexMaxNumber=0;
            int secondMaximumNumber=INT_MIN;

            for (int i=0;i<nums.size();i++){
                if (nums[i]>secondMaximumNumber){
                    if (nums[i]>firstMaximumNumber){
                        secondMaximumNumber=firstMaximumNumber;
                        firstMaximumNumber=nums[i];
                        indexMaxNumber=i;
                    }
                    else
                        secondMaximumNumber=nums[i];
                }
            }

            if (firstMaximumNumber>=secondMaximumNumber*2)
                return indexMaxNumber;
            else 
                return -1;
        }
    }
};