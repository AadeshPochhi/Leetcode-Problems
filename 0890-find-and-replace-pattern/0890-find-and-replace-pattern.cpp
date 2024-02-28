class Solution {
public:
    bool helper(string word,string pattern){
        unordered_map<char,char>mp;
        vector<bool> seen(26, false);
        for(int j=0;j<word.length();j++){
            char w=word[j];
            char p=pattern[j];
             if (mp.find(w) == mp.end()) {
            if (seen[p - 'a']) {
                return false; 
            }
            mp[w] = p; 
            seen[p - 'a'] = true; 
        } else {
            if (mp[w] != p) {
                return false; 
            }
        }
    }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            bool flag=helper(word,pattern);
            if(flag) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};