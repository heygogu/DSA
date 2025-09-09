class Solution {
public:
    int mod = 1e9+7;
    int dp[1001];

    int solve(int idx,int d,int f,int n){
        if(idx>=n) return 1;

        if(dp[idx]!=-1) return dp[idx];

        int ans=1;
        for(int i=idx+d;i<=min(idx+f,n);i++){
            if(i==idx+f) {ans--; break;}
            ans=(ans%mod + solve(i,d,f,n)%mod)%mod;
        } 

        return dp[idx]=ans;

    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        return solve(1,delay,forget,n);
    }
};