class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> myMap;
        for (int i=0;i<list1.size();i++){
            myMap.insert({list1[i],i});
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> myQueue;
        for (int i=0;i<list2.size();i++){
            auto got=myMap.find(list2[i]);
            if (got!=myMap.end()){
                myQueue.push({i+got->second,got->first});
            }
        }
        int saveMin=myQueue.top().first;
        vector<string> result;
        while(!myQueue.empty() && myQueue.top().first==saveMin){
            result.push_back(myQueue.top().second);
            myQueue.pop();
        }
        return result;
    }
};