
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // 1. Top-right diagonals (ascending)
        for (int startCol = 1; startCol < n; startCol++) {
            priority_queue<int, vector<int>, greater<int>> pq; // min-heap
            int r = 0, c = startCol;
            while (r < n && c < n) {
                pq.push(grid[r][c]);
                r++; c++;
            }
            r = 0, c = startCol;
            while (r < n && c < n) {
                grid[r][c] = pq.top();
                pq.pop();
                r++; c++;
            }
        }

        // 2. Bottom-left diagonals (descending, include main)
        for (int startRow = 0; startRow < n; startRow++) {
            priority_queue<int> pq; // max-heap
            int r = startRow, c = 0;
            while (r < n && c < n) {
                pq.push(grid[r][c]);
                r++; c++;
            }
            r = startRow, c = 0;
            while (r < n && c < n) {
                grid[r][c] = pq.top();
                pq.pop();
                r++; c++;
            }
        }

        return grid;
    }
};