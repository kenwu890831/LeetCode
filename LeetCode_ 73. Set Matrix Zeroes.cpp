class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size() ;
        vector< bool > x( m, false ), y( n, false ) ;
        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( matrix[i][j] == 0 ) {
                    x[i] = true ;
                    y[j] = true ;
                }
            }
        }

        for ( int i = 0 ; i < m ; i++ ) {
            if ( x[i] == true ) {
                for ( int j = 0 ; j < n ; j++ ) {
                    matrix[i][j] = 0 ;
                }
            }
        }

        for ( int i = 0 ; i < n ; i++ ) {
            if ( y[i] == true ) {
                for ( int j = 0 ; j < m ; j++ ) {
                    matrix[j][i] = 0 ;
                }
            }
        }

    }
};