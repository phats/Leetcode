class Solution {
public:
    void nextRotate(string str,queue<string>&q){
        for (int i=0;i<4;i++){
            char save=str[i];
            int next=str[i]-'0';
            //quay tien
            str[i]=(next+1)%10 +'0';
            q.push(str);
            //quay nguoc lai
            str[i]=(next-1+10)%10+'0';
            q.push(str);
            str[i]=save;
        }
        return ;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(),deadends.end());
        queue<string> q;
        q.push("0000");
        int count=-1;
        while(!q.empty()){
            count++;
            int n=q.size();
            for (int i=0;i<n;i++){
                string f=q.front();
                q.pop();
                if (f==target){
                    return count;
                }
                if (visited.find(f)==visited.end()){
                    visited.insert(f);
                    nextRotate(f,q);
                }
            }
            
        }
        return -1;
    }
};