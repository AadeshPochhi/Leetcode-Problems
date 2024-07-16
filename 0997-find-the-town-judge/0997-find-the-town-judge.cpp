class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()<n-1) return -1;
        vector<int>score(n+1,0);
        for(auto edge:trust){
            score[edge[0]]--;
            score[edge[1]]++;
        }
        for(int i=1;i<score.size();i++){
            if(score[i]==n-1) return i;
        }
        return -1;
    }
};