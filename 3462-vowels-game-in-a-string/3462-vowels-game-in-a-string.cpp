class Solution {
public:
    bool doesAliceWin(string s) {
        int count=0;
        string vowels = "aeiou";
        for(auto& ch: s){
            if(vowels.find(ch)!=string::npos){
                count++;
                break;
            }
        }
       return count>0;
    }
};