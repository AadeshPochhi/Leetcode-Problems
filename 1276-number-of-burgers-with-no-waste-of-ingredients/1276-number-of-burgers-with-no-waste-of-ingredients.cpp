class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;

    int a = tomatoSlices;
    int b = cheeseSlices;
    double x,y;
    x = (double)(a-2*b)/(double)2;
    y = (double)(4*b-a)/(double)2;
    if(x==(int)x && y==(int)y && x>=0 && y>=0){
    ans.push_back(x);
    ans.push_back(y);
    }
    return ans;
    }
};