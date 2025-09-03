
class Solution {
public:
    vector<int>size;
    vector<int>parent;

    int find(int x){
        return parent[x]=(parent[x]==x)?x:find(parent[x]);
    }

    void union_dsu(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return;

        //otherwise check the sizes
        if(size[a]>=size[b]){
            parent[b]=a;
            size[a]+=size[b];
            size[b]=0;
        }
        else{
            parent[a]=b;
            size[b]+=size[a];
            size[a]=0;
        }
    }

   
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        int m = isConnected[0].size();

        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        size.resize(n,1);

        //create an edgelist
        vector<pair<int,int>>edgeList;


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isConnected[i][j] == 1) {
                    edgeList.push_back({i,j});
                }
            }
        }

        //after creating this edge list I can apply dsu
        for(auto pp:edgeList){
            union_dsu(pp.first,pp.second);
        }
        
        for(auto s:size){
            if(s>0) ans++;
        }
        return ans;
    }
};