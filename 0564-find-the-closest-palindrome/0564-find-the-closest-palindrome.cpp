class Solution {
public:
    
    unsigned long long changeToNum(string&s){

        unsigned long long ans = 0;
        for(int i = 0;i<s.length();i++){
            ans+=(s[i]-'0');
            ans*=10;
        }
        ans/=10;
       
        return ans;
    }

    string changeToStr(unsigned long long num){
        
        string ans;
        while(num>0){
            ans = char('0'+num%10) + ans;
            num/=10;
        }
        
        return ans==""?"0":ans;
    }

    unsigned long long helper1(string&s){
        string t = s;
        
        int curr = (s.length()+1)/2 - 1;
        while(curr>=0){
            
            if(curr == 0 && t[curr] == '1'){break;}
            if(t[curr] == '0')curr--;
            else {
                
                char temp = t[curr] - 1;
                t[curr] = temp;
                t[s.length()-curr-1] = temp;
                break;
            }
        }
        
    	if(t == s){
            
            string temp;
            for(int i = 1;i<t.length();i++){   
                temp+='9';
            }
            if(temp == "")temp = "0";
            return changeToNum(temp);
        }

        for(int i= curr+1;i<s.length() && i<=s.length()-(curr+1)-1;i++){
            t[i] = '9';
        }
        return changeToNum(t);
    }

    unsigned long long helper2(string&s){
        string t = s;
        int curr = (s.length()+1)/2 - 1;
        while(curr>=0){
            if(t[curr] == '9')curr--;
            else{
                
                char temp = t[curr]+1;
                t[curr] = temp;
                t[s.length()-curr-1] = temp;
                break;
            }
        }

        if(s == t){
            
            string temp ;
            for(int i = 0;i<t.length()-1;i++){
                temp += '0';
            }
            
            temp = '1' + temp + '1';
            return changeToNum(temp);
        }

        for(int i = curr+1;i<s.length() && i<=s.length()-(curr+1)-1;i++){
            t[i] = '0';
        }
        return changeToNum(t);
    }

    string nearestPalindromic(string&s) {
        string temp = s;
        for(int i = (s.length()+1)/2;i<s.length();i++){
            temp[i] = s[s.length()-i-1];
        }

        
        
        unsigned long long num1 = changeToNum(s);
        unsigned long long num2 = changeToNum(temp);
        if(num1 == num2){
            unsigned long long a = helper1(temp);
            unsigned long long b = helper2(temp);
            if((num1-a)<=(b-num1))return changeToStr(a);
            else{
                return changeToStr(b);
            }
        }
        else if(num1>num2){
            unsigned long long a = helper2(temp);
            if((num1-num2)<=(a-num1))return changeToStr(num2);
            else return changeToStr(a);
        }
        else{
            unsigned long long a = helper1(temp);
            if((num1-a)<=(num2-num1))return changeToStr(a);
            else return changeToStr(num2);
        }

        return "";
    }
};