class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;

        vector<pair<int,int>> dirs = { {-1,-1}, {-1,1}, {1,-1}, {1,1} } ;
        vector<vector<vector<int>>> dp( rows, vector<vector<int>>(cols, vector<int>(4, 1)) ) ; 

        for ( int r = 0; r < rows ; r++ ) {
            for ( int c = 0; c < cols; c++ ) {
                int val = grid[r][c] ;
                if ( val == 1 ) {
                    ans = 1 ;
                    continue ;
                }
                for ( int d = 0; d < 2; d++ ) {
                    int pr = r + dirs[d].first ;
                    int pc = c + dirs[d].second ;
                    if ( pr >= 0 && pr < rows && pc >= 0 && pc < cols && grid[pr][pc] == 2 - val ) {
                        dp[r][c][d] = dp[pr][pc][d] + 1 ;
                    }
                }
            }
        }

        for ( int r = rows - 1; r >= 0; r-- ) {
            for ( int c = 0; c < cols; c++ ) {
                int val = grid[r][c] ;
                if (val == 1) 
                    continue ;
                for ( int d = 2; d < 4; d++ ) {
                    int pr = r + dirs[d].first, pc = c + dirs[d].second ;
                    if ( pr >= 0 && pr < rows && pc >= 0 && pc < cols && grid[pr][pc] == 2 - val ) {
                        dp[r][c][d] = dp[pr][pc][d] + 1 ;
                    }
                }
            }
        }

        for ( int r = 0; r < rows; r++ ) {
            for ( int c = 0; c < cols; c++ ) {
                int val = grid[r][c] ;
                if (val == 1) 
                    continue ;

                if ( (dp[r][c][0] % 2 == 0 && val == 0) || (dp[r][c][0] % 2 == 1 && val == 2) ) {
                    int nr = r - dp[r][c][0], nc = c - dp[r][c][0] ;
                    if ( nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1 ) {
                        ans = max( ans, dp[r][c][2] + dp[r][c][0] ) ;
                    }
                }

                if ( (dp[r][c][1] % 2 == 0 && val == 0) || (dp[r][c][1] % 2 == 1 && val == 2) ) {
                    int nr = r - dp[r][c][1], nc = c + dp[r][c][1] ;
                    if ( nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1 ) {
                        ans = max( ans, dp[r][c][0] + dp[r][c][1] ) ;
                    }
                }

                if ( (dp[r][c][2] % 2 == 0 && val == 0) || (dp[r][c][2] % 2 == 1 && val == 2) ) {
                    int nr = r + dp[r][c][2], nc = c - dp[r][c][2] ;
                    if ( nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1 ) {
                        ans = max( ans, dp[r][c][3] + dp[r][c][2] ) ;
                    }
                }

                if ( (dp[r][c][3] % 2 == 0 && val == 0) || (dp[r][c][3] % 2 == 1 && val == 2) ) {
                    int nr = r + dp[r][c][3], nc = c + dp[r][c][3] ;
                    if ( nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1 ) {
                        ans = max( ans, dp[r][c][1] + dp[r][c][3] ) ;
                    }
                }
            }
        }

        return ans ;
    }
};
