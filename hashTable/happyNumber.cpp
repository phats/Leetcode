class Solution {
public:
    int sumDigit(int num){
        int res=0;
        while(num>0){
            int digit=num%10;
            res=res+digit*digit;
            num/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> myset;
        while(true){
            int sum=sumDigit(n);
            if (sum==1){
                return true;
            }
            auto got=myset.find(sum);
            if (got!=myset.end()){
                return false;
            }
            else{
                myset.insert(sum);
            }
            n=sum;
        }
        return false;
    }
};