class Solution {
public:
    char findTheDifference(string s, string t) {
        int sums=0;
        int sumt=0;
        for(char c :s){
            sums+=c;
        }
        for(char c :t){
            sumt+=c;
        }
        return char(sumt-sums);
        
    }
};