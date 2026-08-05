class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> temp(n) ;
        vector<int> vis( n, 0 ),ans ;
        queue<int> q ;
        for ( int i = 0 ; i < invocations.size() ; i++ ) {
            temp[invocations[i][0]].push_back(invocations[i][1]) ;
        }

        q.push(k) ;
        vis[k] = 1 ;
        while( !q.empty() ) {
            int t = q.front() ;
            for ( int i = 0 ; i < temp[t].size() ; i++ ) {
                if ( !vis[temp[t][i]] ) {
                    vis[temp[t][i]] = 1 ;
                    q.push(temp[t][i]) ;
                }
            }

            q.pop() ;
        }

        for ( int i = 0 ; i < invocations.size() ; i++ ) {
            if ( !vis[invocations[i][0]] && vis[invocations[i][1]] ) {
                for ( int j = 0 ; j < n ; j++ ) {
                    ans.push_back(j) ;
                }

                return ans ;
            }
        }



        for ( int i = 0 ; i < n ; i++ ) {
            if ( vis[i] != 1 ) {
                ans.push_back(i) ;
            }
        }

        return ans ;
    }

};