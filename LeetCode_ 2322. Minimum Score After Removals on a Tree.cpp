class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> xorSum(n, 0);
        vector<int> in(n), out(n), parent(n, -1);
        int totalXor = 0, time = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            xorSum[u] = nums[u];
            in[u] = time++;
            for (int v : adj[u]) {
                if (v == p) continue;
                parent[v] = u;
                dfs(v, u);
                xorSum[u] ^= xorSum[v];
            }
            out[u] = time++;
        };

        dfs(0, -1);
        totalXor = xorSum[0];

        auto isDescendant = [&](int u, int v) {
            return in[v] > in[u] && out[v] < out[u];
        };

        int res = INT_MAX;
        int m = edges.size();
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m; j++) {
                int a = edges[i][0], b = edges[i][1];
                int u = parent[a] == b ? a : b;

                int c = edges[j][0], d = edges[j][1];
                int v = parent[c] == d ? c : d;

                vector<int> parts;
                if (isDescendant(u, v)) {
                    int x = xorSum[v];
                    int y = xorSum[u] ^ xorSum[v];
                    int z = totalXor ^ xorSum[u];
                    parts = {x, y, z};
                } else if (isDescendant(v, u)) {
                    int x = xorSum[u];
                    int y = xorSum[v] ^ xorSum[u];
                    int z = totalXor ^ xorSum[v];
                    parts = {x, y, z};
                } else {
                    int x = xorSum[u];
                    int y = xorSum[v];
                    int z = totalXor ^ x ^ y;
                    parts = {x, y, z};
                }

                int maxVal = *max_element(parts.begin(), parts.end());
                int minVal = *min_element(parts.begin(), parts.end());
                res = min(res, maxVal - minVal);
            }
        }

        return res;
    }
};
