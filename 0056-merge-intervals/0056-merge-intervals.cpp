class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        sort(it.begin(),it.end());
        int last=0;
        for(int i=0;i<it.size();i++){
            int a=it[last][0];
            int c=it[last][1];
            int b=it[i][0];
            int d=it[i][1];

            if(b>c){
                last++;
                it[last]=it[i];
            }
            else{
                it[last][0]=min(a,b);
                it[last][1]=max(c,d);
            }
        }
        int x=it.size()-last;
        while(it.size()>last+1){
            it.pop_back();
        }
        return it;
    }
};