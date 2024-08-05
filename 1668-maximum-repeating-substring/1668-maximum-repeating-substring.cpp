class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int len=sequence.size();
        int l=word.size();
        vector<int>dp(len+1,0);
        for(int i=l;i<=len;i++){
            if(sequence.substr(i-l,l)==word){
                dp[i]=dp[i-l]+1;
            }
        }
        return *max_element(dp.begin(),dp.end());
        // int cnt = 0;
        // string temp = word;
        // while(sequence.find(temp)!=string::npos)
        // {
        //     temp += word;
        //     cnt++;
        // }
        // return cnt;
    }
};