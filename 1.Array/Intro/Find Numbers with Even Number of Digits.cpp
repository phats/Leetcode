class Solution {
public:
    int count_numbersofdigit(int n){
        int count=0;
        while(true){
            n=n/10;
            count++;
            if(n==0) break;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for (int i=0;i<nums.size();i++){
            if (count_numbersofdigit(nums[i]) %2 ==0){
                count++;
            }
        }
        return count;
    }
};