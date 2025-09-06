class Solution {
public:
    long solve(long l , long r){
        long low=1; long k=1; long sum=0;
        while(k>0){
            if(low>r){
                break;
            }

            long high = low*4-1;

            int start = max(l,low);
            int end = min(r,high);

            if(start<=end){
                sum+= (end-start+1)*k;
            }

            low = low*4;k++;
        }
        return sum;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;

        for(auto& query:queries){
            long steps = solve(query[0],query[1]);
            ans += (steps+1)/2;
        }

        return ans;
    }
};