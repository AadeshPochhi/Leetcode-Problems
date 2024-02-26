class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        map<char,int>count;
        for(char ch : stones)
            count[ch]++;
        for(char ch : jewels)
            ans+=count[ch];
        return ans;
    }
};