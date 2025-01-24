class Solution {
public:
    bool dfs( int node, vector<vector<int>>& adj, vector<int>& state ) {
        if ( state[node] == 1 ) { 
            return true ;
        }
        if ( state[node] == 2 ) { 
            return false ;
        }
        
        state[node] = 1 ; 
        for ( auto neighbor : adj[node] ) {
            if (dfs( neighbor, adj, state )) {
                return true ; 
            }
        }
        state[node] = 2 ;
        return false ;
    }
    
    vector<int> eventualSafeNodes( vector<vector<int>>& graph ) {
        int n = graph.size() ;
        vector<int> state( n, 0 ) ; 
        vector<int> result ;
        
        for ( int i = 0; i < n; i++ ) {
            dfs(i, graph, state ) ; 
        }
        

        for ( int i = 0; i < n; i++ ) {
            if ( state[i] == 2 ) {
                result.push_back(i) ;
            }
        }
        return result;
    }
};
