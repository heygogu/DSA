class Solution {
public:
    bool isPowerOfFour(int n) {
       if((n&1 && n!=1) || n==0 ) return false;
        
        while(n%4==0){
            n=n/4;
        }

       return (n==1) ? true : false; 
    }
};