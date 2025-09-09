class Solution {
public:
    int mod = 1e9+7;
    int dp[1001];

    int solve(int day,int d,int f,int n){
        if(day>=n) return 1;

        if(dp[day]!=-1) return dp[day];

        int ans=1;
        for(int i=day+d;i<=min(day+f,n);i++){
            if(i==day+f) {ans--; break;}
            ans=(ans%mod + solve(i,d,f,n)%mod)%mod;
        } 

        return dp[day]=ans;

    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        return solve(1,delay,forget,n);
    }
};