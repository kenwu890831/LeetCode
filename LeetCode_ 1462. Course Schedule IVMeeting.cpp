class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bitset<100>> prereq( n ) ;
        vector<vector<int>> adj( n ) ;
        vector<int> inDegree( n, 0 ) ;

        for ( auto& edge : prerequisites ) {
            adj[edge[0]].push_back(edge[1]) ;
            prereq[edge[1]].set( edge[0] ) ;
            inDegree[edge[1]]++ ;
        }

        queue< int > q ;
        for ( int i = 0; i < n; ++i )
            if (inDegree[i] == 0) 
              q.push(i) ;

        while ( !q.empty() ) {
            int u = q.front() ;
            q.pop() ;
            for ( int v : adj[u] ) {
                prereq[v] |= prereq[u] ;
                if ( --inDegree[v] == 0  )
                  q.push(v) ;
            }
        }

        vector< bool > ans ;
        for ( auto& qry : queries )
            ans.push_back( prereq[qry[1]][qry[0]] ); 

        return ans ;
    }
};
