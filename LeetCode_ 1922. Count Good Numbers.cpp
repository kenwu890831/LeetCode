class Solution {
public:
    const int mod = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2 ;
        long long odd = n - even ;
        long long result = ( cal( 4, odd ) * cal( 5, even )) % mod ;
        return result ;
    }


    long long cal ( long long mul, long long c ) {
        long long result = 1 ;
        while ( c > 0 ) {
            if ( c % 2 == 1 ) 
                result = ( result * mul ) % mod ;
            mul = ( mul* mul ) % mod ;
            c /= 2 ;
        }

        return result ;
    }
};