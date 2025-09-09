class Solution {
public:
    int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int count = 1;
        vector <int> dp(n+1,0);
        
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
 
            if(i-delay>=1) dp[i]++;
 
            for(int j = max(1,i-forget+1); j<=max(1,i-delay); j++)
                dp[i] = (dp[i]%mod + dp[j]%mod)%mod;
            
            if(i-forget>=1) dp[i]--;
        }
        return dp[n]%mod;
    }
};