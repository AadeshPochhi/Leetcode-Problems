class Solution {
public:
    int maxRepeating(string sequence, string word) {
//         int len=sequence.size();
//         int l=word.size();
//         int j=0;
//         for(int i=0;i<len;i++){
//             if(sequence[i]==word[j]){
//                 int temp=i
//                 while((temp++)<len && (j++)<l && sequence[temp++]==word[j++]){
                    
//                 }
                
//             }
//         }
        int cnt = 0;
        string temp = word;
        while(sequence.find(temp)!=string::npos)
        {
            temp += word;
            cnt++;
        }
        return cnt;
    }
};