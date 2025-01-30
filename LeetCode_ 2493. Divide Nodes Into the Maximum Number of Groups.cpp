class Solution {
    vector<int> next[501];
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        for (auto& edge : edges) {
            next[edge[0]].push_back(edge[1]);
            next[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> groupMaxDepth;

        for (int node = 1; node <= n; node++) {
            int depth = 0, minNodeId = INT_MAX;
            vector<int> level(505);
            queue<int> q;
            q.push(node);
            level[node] = 1;

            while (!q.empty()) {
                depth++;
                int nodesAtCurrentLevel = q.size();
                while (nodesAtCurrentLevel--) {
                    int current = q.front();
                    q.pop();
                    minNodeId = min(minNodeId, current);

                    for (int neighbor : next[current]) {
                        if (level[neighbor] == 0) {
                            level[neighbor] = depth + 1;
                            q.push(neighbor);
                        } else if (level[neighbor] == depth) {
                            return -1;
                        }
                    }
                }
            }
            groupMaxDepth[minNodeId] = max(groupMaxDepth[minNodeId], depth);
        }

        int totalMaxDepth = 0;
        for (auto& [_, maxDepth] : groupMaxDepth)
            totalMaxDepth += maxDepth;

        return totalMaxDepth;
    }
};
