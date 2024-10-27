class Solution {
public:
    bool check ( int edge, int x, int y, vector<vector<int>>& matrix ) {
        if ( edge == 0 ) {
            if ( matrix[x][y] == 1 )
              return true ;
            return false ;
        }


        for ( int m = x ; m <= x + edge ; m++ ) {
            for ( int n = y ; n <= y + edge ; n++ ) {
              if ( matrix[m][n] == 0 )
                return false ;
            }
        }

        return true ;
    }


    int countSquares(vector<vector<int>>& matrix) {
        int edge = 0, count = 0 ;
        if ( matrix.size() <= matrix[0].size() )
          edge = matrix.size() ;
        else 
          edge = matrix[0].size() ;

        for ( int i = 0 ; i < edge ; i++ ) {
            for ( int m = 0 ; m < matrix.size()-i ; m++ ) {
                for ( int n = 0 ; n < matrix[0].size()-i ; n++ ) {
                    if ( check( i, m, n, matrix ) )
                      count++ ;
                }
            }
        }


        return count ;
    }
};