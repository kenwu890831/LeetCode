class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size() ;
        int result = 0 ;
        vector< int > temp( m + n , 0 ) ;
        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( grid[i][j] == 1 ) {
                    temp[i]++ ;
                    temp[m+j]++ ;
                    result++ ;

                }
                
            }
        }


        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( grid[i][j] == 1 && temp[i] == 1 && temp[m+j] == 1 ) {
                  result-- ;
                }
                  
            }
        }



        return result ;
    }
};