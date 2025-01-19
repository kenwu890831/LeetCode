class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();

        int directions[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int j = 0; j < n; ++j) {
            pq.emplace(heightMap[0][j], make_pair(0, j));
            pq.emplace(heightMap[m-1][j], make_pair(m-1, j));
            visited[0][j] = visited[m-1][j] = true;
        }

        for (int i = 1; i < m - 1; ++i) {
            pq.emplace(heightMap[i][0], make_pair(i, 0));
            pq.emplace(heightMap[i][n-1], make_pair(i, n-1));
            visited[i][0] = visited[i][n-1] = true;
        }

        int water = 0;

        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();

            int row = cell.first, col = cell.second;

            for (const auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || visited[newRow][newCol])
                    continue;

                if (heightMap[newRow][newCol] < height) {
                    water += height - heightMap[newRow][newCol];
                    pq.emplace(height, make_pair(newRow, newCol));
                } else {
                    pq.emplace(heightMap[newRow][newCol], make_pair(newRow, newCol));
                }

                visited[newRow][newCol] = true;
            }
        }

        return water;
    }
};
