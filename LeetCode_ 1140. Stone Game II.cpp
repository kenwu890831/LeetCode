class Solution {
public:
    vector< int > sumTemp ;
    vector< vector< int > > dp ; 
    int n ;
    int stoneGameII(vector<int>& piles) {
        n = piles.size() ;
        sumTemp.assign( n+1, 0 ) ;
        for ( int i = n - 1 ; i >=0 ; i-- ) {
            sumTemp[i] = sumTemp[i+1] + piles[i] ; //total in piles
        }

        dp.assign( n, vector( n + 1, -1 ) ) ;

        return run( 0, 1 ) ;
    }

    int run( int i, int M ) {
        if ( i == n )
            return 0 ;
        if ( dp[i][M] != -1 ) {
            return dp[i][M] ;
        } // counted

        int best = 0 ;

        for( int X = 1 ; X <= 2 * M && i + X <= n ; X++ ) {
            int nextM = max( X, M ) ;
            int cur = sumTemp[i] - run( i + X, nextM ) ;
            best = max( best, cur ) ;
        }

        dp[i][M] = best ;
        return best ;
    }
};