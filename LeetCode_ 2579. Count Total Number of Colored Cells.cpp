class Solution {
public:
    long long coloredCells(int n) {
        long long result = 1 ;
        for ( int i = 2 ; i <= n ; i++ ) {
            result += ( i*2 + ( i- 2 )*2 ) ;
        }

        return result ;
    }
};