class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n==1 && k==1){
            return 0;
        }
        if (kthGrammar(n-1,k/2+k%2)==0){
            if (k%2==1) return 0;
            else return 1;
        }
        else{
            if (k%2==1) return 1;
            else return 0;
        }
    }
};