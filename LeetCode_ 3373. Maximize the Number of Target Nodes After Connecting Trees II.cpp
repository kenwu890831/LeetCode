class Solution {
public:
    int evenA = 0, oddA = 0, evenB = 0, oddB = 0;

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;

        vector<vector<int>> adj1(n1), adj2(n2);
        vector<int> result(n1);
        adjBuild(edges1, adj1);
        adjBuild(edges2, adj2);

        vector<int> color1(n1, -1), color2(n2, -1);

        evenA = oddA = evenB = oddB = 0;
        bfs(adj1, color1, true);
        bfs(adj2, color2, false);

        int maxB = max(evenB, oddB);

        for (int i = 0; i < n1; ++i) {
            result[i] = (color1[i] == 0 ? evenA : oddA) + maxB;
        }

        return result;
    }

    void bfs(vector<vector<int>>& adj, vector<int>& color, bool isA) {
        queue<int> q;
        q.push(0);
        color[0] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (color[u] == 0) {
                if (isA) evenA++;
                else evenB++;
            } else {
                if (isA) oddA++;
                else oddB++;
            }

            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
            }
        }
    }

    void adjBuild(vector<vector<int>>& edges, vector<vector<int>>& adj) {
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
};
