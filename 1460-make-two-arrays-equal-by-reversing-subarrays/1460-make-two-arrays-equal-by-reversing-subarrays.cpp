class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) return false;
        unordered_map<int,int>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m.find(target[i])==m.end()){
                return false;
            }
            else{
                m[target[i]]--;
                if(m[target[i]]==0) m.erase(target[i]);
            }
        }
        if(m.empty()){
            return true;
        }
        return false;
        
        
        // if (target.size() != arr.size()) return false;
        // unordered_map<int, int> m;
        // for (int i = 0; i < target.size(); i++) {
        //     m[target[i]]++;
        // }
        // for (int i = 0; i < arr.size(); i++) {
        //     if (!m[arr[i]]) return false;
        //     m[arr[i]]--;
        // }
        // return true;

    }
};