class Solution {
public:
    vector<int> sumZero(int n) {

        int left = n/2*-1;
        int right = n/2;
        bool isEven=n%2==0;

        vector<int>ans;
        for(int i=left;i<=right;i++){
            if(isEven && i==0)continue; 
            ans.push_back(i);
        }

        return ans;
    }
};