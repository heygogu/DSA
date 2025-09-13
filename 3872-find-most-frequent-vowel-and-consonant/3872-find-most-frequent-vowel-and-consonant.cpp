class Solution {
public:
    bool isVowel(char& ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        return false;
    }
    int maxFreqSum(string s) {
        if(!s.size()) return 0;

         vector<int>vowels(27,0);
         vector<int>cons(27,0);

         for(auto& ch:s){
            if(isVowel(ch)){
                vowels[ch-96]++;
            }else{
                cons[ch-96]++;
            }
         }

         int maxVowel=0;
         int maxCons=0;
         for(auto& it:vowels){
            if(it>maxVowel) maxVowel=it;
         }
          for(auto& it:cons){
            if(it>maxCons) maxCons=it;
         }
        
        return maxVowel+maxCons;

    }
};