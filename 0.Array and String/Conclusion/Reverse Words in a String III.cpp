class Solution {
public:
    string reverseWords(string s){
        int countChar=0;
        for (int i=0;i<s.length();i++){
            if (s[i]==' '){
                reverse(s.begin()+i-countChar,s.begin()+i);
                countChar=0;
            }
            else{
                ++countChar;
            }
        }
        reverse(s.end()-countChar,s.end());
        return s;
    }
};