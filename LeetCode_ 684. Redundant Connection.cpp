class Solution {
public:
    vector< int > parent ;
    vector< int > rank ;

    int findParent( int i ) {
        if ( parent[i] != i )
            parent[i] = findParent( parent[i] ) ; 
        return parent[i] ;
    }

    void merge( int u, int v ) {
        int rootU = findParent(u), rootV = findParent(v) ;
        if ( rootU != rootV ) {
            if (rank[rootU] > rank[rootV]) 
              parent[rootV] = rootU ;
            else if (rank[rootU] < rank[rootV]) 
              parent[rootU] = rootV ;
            else {
                parent[rootV] = rootU ;
                rank[rootU]++ ;
            }
        }
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        parent.resize( n + 1 ) ;
        rank.resize( n + 1, 0 ) ;
        
        for ( int i = 1; i <= n; i++ ) 
          parent[i] = i ;

        for ( auto& edge : edges ) {
            int u = edge[0], v = edge[1] ;
            if ( findParent(u) == findParent(v) ) 
              return edge; 
            merge( u, v ) ;
        }
        
        return {} ;  

    }
};