class Solution {
public:
    int mySqrt(int x) {
        int left=0;
        int right=x/2;
        if (x<=1){
            return x;
        }
        while(left<=right){
            long long mid=(left+right)/2;
            long long power=mid*mid;
            if (power==x){
                return mid;
            }
            else if (power>x){
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return left-1;
    }
};