class Solution {
public:
    int m = 1e9 + 7 ;
    bool isPowerOfFour(int n) {
        long long temp = 1 ;
        for ( int i = 0 ; i < 33 ; i++ ) {
            if ( n == temp )
                return true ;
            else if ( temp > n )
                break ;

            temp <<= 2 ;

        }
        


        return false ;
    }
};