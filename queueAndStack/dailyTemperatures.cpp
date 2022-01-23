class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> s_index;
        for (int i=0;i<temperatures.size();i++){
            while(s_index.size()!=0 && temperatures[i]>temperatures[s_index.top()]){
                res[s_index.top()]=i-s_index.top();
                s_index.pop();
            }
            s_index.push(i);
        }
        return res;
    }
};