class Solution {
public:

    int maxMoves(vector<vector<int>>& grid) {
        int result = 0, current = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for ( int i = 0; i < n; i++ ) {
          dp [ i ][ 0 ] = 1;
        }

        

        for ( int j = 1 ; j < m ; j++ ) {
            for ( int i = 0 ; i < n ; i++ ) {
              int curr = grid[i][j] ;
              int max = 0 ;
              bool check = false ;
              
              if ( i-1 >= 0 && grid[i-1][j-1] < curr && dp[i-1][j-1] != 0) {
                max = dp[i-1][j-1] ;
                check = true ;
              }

              if ( grid[i][j-1] < curr && dp[i][j-1] != 0) {
                max = dp[i][j-1] ;
                check = true ;
              }

              if ( i+1 < n && grid[i+1][j-1] < curr && dp[i+1][j-1] != 0) {
                max = dp[i+1][j-1] ;
                check = true ;
              }
          
              if ( check ) {
                dp[i][j] = max + 1 ; 
                if ( max > result )
                  result = max ;
              }
              
            }

        } 
            
        


        return result ;
    }
};