class Solution {
public:
    int m = 1e9 + 7 ;
    long long flowerGame(int n, int m) {
        if ( ( n + m )  <= 2 )
            return 0 ;

        long long n1 = ( n + 1) / 2, n2 = ( n ) / 2, m1 = ( m + 1 ) / 2, m2 = ( m ) / 2 ;
        
        return ( n1 * m2 ) + ( n2 * m1 )  ;
    }
};