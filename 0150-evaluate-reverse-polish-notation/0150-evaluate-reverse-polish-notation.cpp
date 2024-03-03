class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string>op={"+","-","*","/"};
        stack<int>sk;
        for(const auto& t:tokens)
        {
            if(op.find(t)==op.end()){
                sk.push(stoi(t));
            }
            else{
                int n1=sk.top(); sk.pop();
                int n2=sk.top(); sk.pop();
                if(t=="+") sk.push(n1+n2);
                else if(t=="-") sk.push(n2-n1);
                else if(t=="*") sk.push(n1*n2);
                else if(t=="/") sk.push(n2/n1);
            }
        }
        return sk.top();
    }
};