
class Solution {
public:
    vector<int> size;
    vector<int> parent;

    int find(int x) {
        return parent[x] = (parent[x] == x) ? x : find(parent[x]);
    }

    void union_dsu(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        // otherwise check the sizes
        if (size[a] >= size[b]) {
            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
        } else {
            parent[a] = b;
            size[b] += size[a];
            size[a] = 0;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();

        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { 
                if (isConnected[i][j] == 1)
                    union_dsu(i, j);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                ans++;
        }
        return ans;
    }
};