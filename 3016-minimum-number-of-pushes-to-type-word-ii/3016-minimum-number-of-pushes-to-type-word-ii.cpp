class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char ch: word){
            freq[ch-'a']++;
        }
        sort(freq.begin(), freq.end());
        int ans=0;
        int j=0;
        for(int i=25;i>=0;i--){
            ans+=(freq[i])*((j/8)+1);
            j++;
        }
        return ans;
    }
};