class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() ;
        int top = INT_MIN, bot = INT_MAX, right = INT_MIN, left = INT_MAX ;
        for( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( grid[i][j] == 1 ) {
                    top = max( top, i ) ;
                    bot = min( bot, i ) ;
                    right = max( right, j ) ;
                    left = min( left, j ) ;
                }
            }
        }

        return ( top - bot + 1 )*( right - left + 1) ;
    }
};