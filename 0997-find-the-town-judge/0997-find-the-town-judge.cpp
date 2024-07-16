class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()<n-1) return -1;
        if(n==1) return 1;
        vector<int>score(n+1,0);
        for(auto edge:trust){
            score[edge[0]]--;
            score[edge[1]]++;
        }
        auto it=find(score.begin(),score.end(),n-1);
        if(it!=score.end()){
            return distance(score.begin(),it);
        }
        return -1;
    }
};