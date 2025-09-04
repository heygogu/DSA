class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsetSize= 1<<nums.size();
        int n = nums.size();

        vector<vector<int>>ans;
        for(int i=0;i<subsetSize;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};