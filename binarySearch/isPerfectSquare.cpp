class Solution {
public:
    bool isPerfectSquare(int num) {
        int left=1,right=num/2;
        if (num==1){
            return true;
        }
        while(left<=right){
            long long mid=(left+right)/2;
            long long square=mid*mid;
            if (num==square){
                return true;
            }
            else if (square>num){
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return false;
    }
};