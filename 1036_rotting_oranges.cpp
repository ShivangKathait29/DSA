class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty() && fresh > 0) {
            int size = q.size();

            for (int k = 0; k < size; k++) {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    if (grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }

            ans++;
        }

        return fresh == 0 ? ans : -1;
    }
};