class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size() ;
        unordered_map<int, pair<int, int> > map;
        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
              map[ mat[i][j] ] = { i, j } ;
            }
        }

        vector< int > rCount( m, n ) ;
        vector< int > cCount( n, m ) ;

        for ( int i = 0 ; i < arr.size() ; i++ ) {
            auto [ row, col ] = map[ arr[i] ] ;

            if ( --rCount[ row ] == 0 || --cCount[ col ] == 0 )
              return i ;
        }

        
        return 0 ;
    }
};