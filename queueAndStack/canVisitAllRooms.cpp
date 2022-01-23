class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<vector<int>> q;
        vector<int> isVisited(rooms.size(),false);
        q.push(rooms[0]);
        isVisited[0]=true;
        while(!q.empty()){
            int n=q.size();
            for (int i=0;i<n;i++){
                vector<int> front=q.front();
                q.pop();
                for (int j=0;j<front.size();j++){
                    if (!isVisited[front[j]]){
                        q.push(rooms[front[j]]);
                        isVisited[front[j]]=true;
                    }
                }
            }
            
        }
        for (int i=0;i<isVisited.size();i++){
            if (!isVisited[i]){
                return false;
            }
        }
        return true;
    }
};