class Solution {
public:
    long long countCommas(long long n) {
        if ( n < 1000 )
            return 0 ;

        long long ans = 0 ;
        for ( long long i = 1000, dot = 1 ; i <= n ; i*=1000, dot++ ) {
            long long temp = min( n+1, 1000*i ) ;
            ans += ( temp - i )*dot ;
        }

        return ans ;
    }
};