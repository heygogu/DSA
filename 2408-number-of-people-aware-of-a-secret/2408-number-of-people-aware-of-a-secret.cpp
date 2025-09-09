class Solution {
public:
    #define MOD 1000000007;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long curr = 0;

        unordered_map<int,int>mp(n+1);
        mp[1]=1;

        for(int i=2;i<=n;i++){
            //check how many are eligible
            curr += mp[i-delay];

            //remove how many have forgetten
            curr-= mp[i-forget];
            mp[i]=curr%MOD;
        }

        long count=0;
        for(int i=1;i<=n;i++){
            count+=mp[i];
            count-=mp[i-forget];
        }

        return count%MOD;

    }
};