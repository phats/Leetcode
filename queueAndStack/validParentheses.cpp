class Solution {
public:
    int open(char ch){
        switch(ch){
            case '(': return 1;
            case '[': return 2;
            case '{': return 3;
            default: return 0;
        }
    }
    int close(char ch){
        switch(ch){
            case ')': return 1;
            case ']': return 2;
            case '}': return 3;
            default: return 0;
        }
    }
    bool isValid(string s) {
        stack<char> st;
        for (int i=0;i<s.length();i++){
            if (open(s[i])!=0){
                st.push(s[i]);
            }
            else if (close(s[i])!=0){
                if (st.size()==0){
                    return false;
                }
                else{
                    if (close(s[i])==open(st.top())){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return (st.size()==0);
    }
};