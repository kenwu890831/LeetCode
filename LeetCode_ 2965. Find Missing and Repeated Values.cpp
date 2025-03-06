class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int twice = 0, miss = 0, n = grid.size() ;
        vector< int > temp( n*n, 0 ) ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                temp[grid[i][j]-1]++ ;
            }
        }

        for ( int i = 0 ; i < temp.size() ; i++ ) {
            if ( temp[i] == 0 ) {
                miss = i + 1 ;
            }
            else if ( temp[i] == 2 ) {
                twice = i + 1 ;
            }
        }

        return { twice, miss } ;
    }
};