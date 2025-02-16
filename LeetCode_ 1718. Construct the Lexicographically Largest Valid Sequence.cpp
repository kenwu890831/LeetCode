class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2*n - 1 ;
        vector< int > result( 2*n - 1, 0 ) ;
        vector< bool > check( n, false ) ;
        construct( result, check, n ) ;

        return result ;
    }

    bool construct ( vector< int >& result, vector< bool >& check, int n ) {
        int index = 0 ;
        while( index < result.size() && result[index] != 0 ) {
            index++ ;
        }

        if ( index == result.size() )
            return true ;
        
        for ( int i = n ; i > 0 ; i-- ) {
            if ( check[i] == true )
                continue ;
            if ( i == 1 ) {
                result[index] = 1 ;
                check[i] = true ;
                if ( construct( result, check, n ) )
                  return true ;
                result[index] = 0 ;
                check[i] = false ;
            }
            else if ( ( index + i ) < result.size() && result[index + i] == 0 ){
                result[index] = i ;
                result[index+i] = i ;
                check[i] = true ;
                if ( construct( result, check, n ) )
                  return true ;
                result[index] = 0 ;
                result[index+i] = 0 ;
                check[i] = false ;
            }
        }

        return false ;

        
    }
};