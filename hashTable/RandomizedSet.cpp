class RandomizedSet {
public:
    vector<int> arr;
    unordered_map <int, int> myMap;
    // first: nums[i] | second: index
    int index = 0;
    RandomizedSet() {

    }

    bool insert(int val) {
        if (myMap.find(val) != myMap.end()) {
            return false;
        }
        else {
            cout<<val<<endl;
            arr.push_back(val);
            myMap.insert({ val,index });
            ++index;
            return true;
        }
    }

    bool remove(int val) {
        auto got = myMap.find(val);
        if (got != myMap.end()) {
            // swap to end index
            arr[got->second] = arr[arr.size() - 1];
            myMap[arr[arr.size() - 1]] = got->second;
            
            arr.pop_back();
            myMap.erase(got);
            --index;
            return true;
        }
        else {
            return false;
        }
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */