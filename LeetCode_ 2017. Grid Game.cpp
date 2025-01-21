class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long result = LLONG_MAX ;
        long long top = accumulate( grid[0].begin(), grid[0].end(), 0LL ) ;
        long long bottom = 0 ;

        for ( int i = 0 ; i < grid[0].size(); i++ ) {
            top -= grid[0][i] ;
            result = min( result, max( top, bottom )) ;
            bottom += grid[1][i] ;
        }


        return result ;



    }
};