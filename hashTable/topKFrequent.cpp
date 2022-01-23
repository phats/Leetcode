class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> Frequency;
        //first: nums[i] | second: number of occurrences
        for (int i=0;i<nums.size();i++){
            auto got=Frequency.find(nums[i]);
            if (got!=Frequency.end()){
                ++got->second;
            }
            else{
                Frequency.insert({nums[i],1});
            }
        }
        vector<pair<int,int>> occurrences;
        // first: number of occurrences | second: nums[i]
        for (auto i=Frequency.begin();i!=Frequency.end();i++){
            occurrences.push_back({i->second,i->first});
        }
        sort(occurrences.begin(),occurrences.end());
        int count=0;
        vector<int> result;
        for (int i=occurrences.size()-1;i>=0;i--){
            count++;
            result.push_back(occurrences[i].second);
            if (count==k){
                break;
            }
        }
        return result;
    }
};