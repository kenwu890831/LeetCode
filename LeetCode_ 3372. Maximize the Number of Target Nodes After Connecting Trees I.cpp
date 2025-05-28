class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int size1 = edges1.size() + 1, size2 = edges2.size() + 1 ;
        vector<vector<int>> adj1( size1 ), adj2( size2 ) ;
        vector< int > result( size1 ) ;
        adjBuild( edges1, adj1 ) ;
        adjBuild( edges2, adj2 ) ;
        int temp = 0 ;
        for ( int i = 0 ; i < size2 ; i++ ) {
            temp = max( temp, dfs( i, -1, k - 1, adj2 ) ) ;
        }
        for ( int i = 0 ; i < size1 ; i++ ) {
            result[i] = dfs( i, -1, k , adj1 ) + temp;
        }

        return result ;
    }

    void adjBuild( vector<vector<int>>& edges, vector<vector<int>>& adj ) {
        for ( int i = 0; i < edges.size() ; i++ ) {
            int x = edges[i][0], y = edges[i][1] ;
            adj[x].push_back( y ) ;
            adj[y].push_back( x ) ;
        }
    }

    int dfs( int index, int parent,  int k, const vector<vector<int>>& adj ){
        if ( k < 0 ) 
            return 0 ;
        int max = 1 ;
        for( int i = 0 ; i < adj[index].size() ; i++ ) {
            if ( adj[index][i] == parent ) 
                continue ;
            max += dfs( adj[index][i], index, k-1, adj ) ;
        }

        return max;
    }
};