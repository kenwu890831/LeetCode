class Solution {
public:
    bool isPowerOfThree(int n) {
        long long temp = 1 ;
        for ( int i = 0 ; i < 32 ; i++ ) {
            if ( temp == n )
                return true ;
            else if ( temp > n )
                break ;

            temp *= 3 ;
        }

        return false ;


    }
};