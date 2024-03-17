class Solution {
public:
    int romanToInt(string str) {
        long num=0;
        for(int i=0;i<str.length();i){
            if(str[i]=='I'&&str[i+1]=='V'){
                num+=4;
                i+=2;
            }else if(str[i]=='I'&&str[i+1]=='X'){
                num+=9;
                i+=2;
            }else if(str[i]=='X'&&str[i+1]=='L'){
                num+=40;
                i+=2;
            }else if(str[i]=='X'&&str[i+1]=='C'){
                num+=90;
                i+=2;
            }else if(str[i]=='C'&&str[i+1]=='D'){
                num+=400;
                i+=2;
            }else if(str[i]=='C'&&str[i+1]=='M'){
                num+=900;
                i+=2;
            }else if(str[i]=='I'){
                num+=1;
                i++;
            }else if(str[i]=='V'){
                num+=5;
                i++;
            }else if(str[i]=='X'){
                num+=10;
                i++;
            }else if(str[i]=='L'){
                num+=50;
                i++;
            }else if(str[i]=='C'){
                num+=100;
                i++;
            }else if(str[i]=='D'){
                num+=500;
                i++;
            }else if(str[i]=='M'){
                num+=1000;
                i++;
            }
        }
        return num;
    }
};