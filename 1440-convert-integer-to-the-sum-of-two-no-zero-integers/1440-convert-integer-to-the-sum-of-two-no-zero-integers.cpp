class Solution {
public:
   bool ContainsZero (int num){
    while(num!=0){
        int digit = num%10;
        if(digit==0) return true;
        num=num/10;
    }
    return false;
   }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i=1;i<n;i++){
            if(ContainsZero(i) || ContainsZero(n-i)) continue;
            ans.push_back(i);
            ans.push_back(n-i);
            break;
        }

        return ans;
    }
};