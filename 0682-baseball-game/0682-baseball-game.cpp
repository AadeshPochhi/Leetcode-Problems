class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int>sk;
        int ans=0;
        for(int i=0;i<op.size();i++){
            if(op[i]=="+"){
                int top=sk.top();
                sk.pop();
                int newtop=top+sk.top();
                sk.push(top);
                sk.push(newtop);
            }
            else if(op[i]=="C"){
                sk.pop();
            }
            else if(op[i]=="D"){
                int top=sk.top();
                sk.push(2*top);
            }
            else{
                int number=stoi(op[i]);
                sk.push(number);
            }
            
        }
        while(!sk.empty()){
            ans+=sk.top();
            sk.pop();
        }
        return ans;
    }
};