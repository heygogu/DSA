class Solution {
public:
    long long flowerGame(int n, int m) {
        
        long long evenInN=n/2;
        long long oddInN= (n%2==0)?n/2:(n/2+1);

        long long evenInM=m/2;
        long long oddInM= (m%2==0)?m/2:(m/2+1);


       return (evenInN*oddInM)+(evenInM*oddInN);
    }
};