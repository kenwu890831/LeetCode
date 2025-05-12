class Solution {
public:
    int n ;
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector< int > result ;
        int count[10] = {0} ;
        for ( int i = 0 ; i < digits.size() ; i++ ) {
            count[digits[i]]++ ;
        }

        for ( int i = 1 ; i <= 9 ; i++ ) {
            if ( count[i] == 0 )
                continue ;
            count[i]-- ;
            for ( int j = 0 ; j <= 9 ; j++ ) {
                if ( count[j] == 0 )
                  continue ;
                count[j]-- ;
                for ( int k = 0 ; k <= 9 ; k+= 2 ) {
                    if ( count[k] >= 1 )
                        result.push_back( i*100 + j*10 + k ) ;
                }

                count[j]++ ;
            }

            count[i]++ ;
        }


        return result ;
    }



};