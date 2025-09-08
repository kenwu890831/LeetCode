class Solution {
public:
    bool check( int input ) {
        while( input > 0 ) {
            if ( input % 10 == 0 )
                return true ;
            input /= 10 ;
        }

        return false ;
    }
    vector<int> getNoZeroIntegers(int n) {
        for ( int i = 1 ; i < n ; i++ ) {
            int j = n - i ;
            if ( !check( i ) && !check( j ) ) {
                return { i, j } ;
            }
        }

        return {} ;
    }
};