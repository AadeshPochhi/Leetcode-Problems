class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
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
    }
};