class Solution {
public:
    string helper(int num, unordered_map<int,string>&myMap){
        if(num<1000){
            int var=1;
            string temp;
            while(num>0){
                int curr=num%(10*var);
                num=num-curr;
                var*=10;
                if((num%100)/10==1){
                    temp=myMap[10+curr]+temp;
                    num-=num%100;
                }
                else if(curr>=100){
                    temp=myMap[curr/100]+" Hundred"+temp;
                }
                else
                    temp=myMap[curr]+temp;
            }
            return temp;
        }
        if(num>=1000000000){
            return helper(((num-(num%1000000000))/1000000000),myMap)+" Billion"+helper((num%1000000000),myMap);
        }
        else if(num>=1000000){
            return helper(((num-(num%1000000))/1000000),myMap)+" Million"+helper((num%1000000),myMap);
        }
        else if(num>=1000){
            return helper(((num-(num%1000))/1000),myMap)+" Thousand"+helper((num%1000),myMap);
        }
        return "";
    }
    string numberToWords(int num) {
        unordered_map<int,string> myMap = {
            {1  ,   " One"},
            {2  ,   " Two"},
            {3  ,   " Three"},
            {4  ,   " Four"},
            {5  ,   " Five"},
            {6  ,   " Six"},
            {7  ,   " Seven"},
            {8  ,   " Eight"},
            {9  ,   " Nine"},
            {10  ,   " Ten"},
            {11  ,   " Eleven"},
            {12  ,   " Twelve"},
            {13  ,   " Thirteen"},
            {14  ,   " Fourteen"},
            {15  ,   " Fifteen"},
            {16  ,   " Sixteen"},
            {17  ,   " Seventeen"},
            {18  ,   " Eighteen"},
            {19  ,   " Nineteen"},
            {20  ,   " Twenty"},
            {30  ,   " Thirty"},
            {40  ,   " Forty"},
            {50  ,   " Fifty"},
            {60  ,   " Sixty"},
            {70  ,   " Seventy"},
            {80  ,   " Eighty"},
            {90  ,   " Ninety"},
        };
        if(num==0) return "Zero";
        string ans=helper(num,myMap);
        return ans.erase(0,1);
        
    }
};