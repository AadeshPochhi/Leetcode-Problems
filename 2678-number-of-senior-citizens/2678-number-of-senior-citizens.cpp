class Solution {
public:
    int countSeniors(vector<string>& details) {
        int p=0;
        for(auto person:details){
            if(stoi(person.substr(11,2))>60){
                p++;
            }
            else{
                continue;
            }
        }
        return p;
    }
};