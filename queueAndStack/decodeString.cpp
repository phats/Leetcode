class Solution {
public:
    bool isNumber(string s){
        return (s[0]>='0' && s[0]<='9');
    }
    string decodeSimple(string s){
        string number,str;
        for (int i=0;i<s.length();i++){
            string char_to_str(1,s[i]);
            if (isNumber(char_to_str)){
                number+=char_to_str;
            }
            else{
                str+=char_to_str;
            }
        }
        string res;
        for (int i=0;i<stoi(number);i++){
            res+=str;
        }
        return res;
    }
    string decodeString(string s) {
        stack<string> s1;
        for (int i=0;i<s.length();i++){
            if (s[i]!=']'){
                string char_to_str(1,s[i]);
                s1.push(char_to_str);
            }
            else{
                //neu gap ki tu ]
                string save_str="";
                bool isNum=false;
                while(!s1.empty()){
                    if (!isNumber(s1.top())){
                        //neu top cua stack khong la so
                        if (isNum){
                            //neu ky tu truoc cua stack la so ma ky tu sau la chu
                            s1.push(decodeSimple(save_str));
                            //chuyen chuoi tu dang don gian vd: 3abc=abcabcabc
                            break;
                        }
                        if (s1.top()!="["){
                            save_str=s1.top()+save_str;
                        }
                    }
                    else {
                        save_str=s1.top()+save_str;
                        if (s1.size()==1){
                            s1.pop();
                            //xoa so da gap
                            s1.push(decodeSimple(save_str));
                            //chuyen chuoi tu dang don gian vd: 3abc=abcabcabc
                            break;
                        }
                        else{
                            //danh dau da gap so
                            isNum=true;
                        }
                    }
                    s1.pop();
                }        
            }
        }
        // trong stack luc nay chi con chua chuoi cac ket qua
        string res=s1.top();
        s1.pop();
        while(!s1.empty()){
            res=s1.top()+res;
            s1.pop();
        }
        return res;
    }
};