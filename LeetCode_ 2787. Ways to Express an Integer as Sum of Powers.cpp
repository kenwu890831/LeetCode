class Solution {
public:
    int m = 1e9 + 7 ;
    int numberOfWays(int n, int x) {
        int ans = 0 ;
        vector< int > temp ;
        vector< long long > dp( n + 1, 0 ) ;
        dp[0] = 1 ;
        for ( int i = 1 ;  ; i++ ) {
            long long sum = 1 ;
            for ( int j = 0 ; j < x ; j++ ) {
                sum = ( sum * i ) % m ;
            }

            if ( sum > n )
                break ;

            temp.push_back( sum ) ;

        }

        for( int i : temp ) {
            for( int j = n ; j >= i ; j-- ) {
                dp[j] = ( dp[j] + dp[ j - i ] ) % m ;
            }
        }


        return (int)dp[n] ;
    }
};