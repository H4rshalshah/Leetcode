class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<int>hash(26,0);
        for(int i=0;i<sentence.size();i++){
            hash[char(sentence[i])-'a']++;
        }
        for(auto it :hash){
            if(it==0){
                return false;
            }
        }
        return true;
        
    }
};